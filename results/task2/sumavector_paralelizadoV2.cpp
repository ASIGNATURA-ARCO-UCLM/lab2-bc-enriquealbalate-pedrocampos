/* Programa secuencial que calcula la suma de los elementos de un vector v[i] y la almacena en la variable sum */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define N 10 // Probar distintos tamaños de vector

int main()
{
    int i, sum = 0;
    int v[N];

    omp_set_num_threads(5);
    // Damos valores aleatorios al vector (entre 0 y 99)
    srand (time(NULL)); // Semilla de números aleatorios
    #pragma omp parallel for
        for (i = 0; i < N; i++) v[i] = rand()%100;

    // Cálculo del sumatorio
    #pragma omp parallel for
        for (i = 0; i < N; i++)
            #pragma omp atomic
                sum += v[i];

    // Como comprobación, se visualizan los valores del vector y la suma
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("\nVector de números: \n ");
            for (i = 0; i < N; i++) printf("%d \t",v[i]);
        }

        #pragma omp section
        {
            printf("\n La suma es: %d \n\n", sum);
        }
    }

    return 0;
}
