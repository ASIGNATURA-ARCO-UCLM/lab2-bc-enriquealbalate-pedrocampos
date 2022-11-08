#include <math.h>
#include <stdio.h>
#include <omp.h>
#include <vector>
#include <time.h>
#include <ctime>
#define N 50 // Probar distintos tamaños de vector

int main()
{
    double a, z;
    int i = 0;
    int maximo = 0;
    int minimo = 0;
    int array[N];

    a = omp_get_wtime();
    omp_set_num_threads(10);
  
    // Damos valores aleatorios al vector (entre 0 y 99)
    srand (time(NULL)); // Semilla de números aleatorios
    #pragma omp parallel for
        for (i = 0; i < N; i++) array[i] = rand()%100;

    maximo = array[0];
    minimo = array[0];

    #pragma omp parallel for
    for (int i=0;i<N;i++){

        #pragma omp critical
        {
            if (maximo < array[i]){
                maximo = array[i];
            }
        }

        #pragma omp critical
        {
            if (minimo > array[i]){
                minimo = array[i];
            }
        }
    }

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("El máximo es el %d \n",maximo);
        }

        #pragma omp section
        {
            printf("El mínimo es el %d \n",minimo);
        }
    }

    z = omp_get_wtime();
    printf("%0.10f\n", z-a);

    return 0;
}
