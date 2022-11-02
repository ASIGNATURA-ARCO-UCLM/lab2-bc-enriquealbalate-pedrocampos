 
El codigo del programa desarrollado es el siguiente:

    #include <math.h> 
    #include <stdio.h> 
    #include <omp.h> 
    #include <vector>
    #include <time.h> 
    #include <ctime>
    #define N 50 // Probar distintos tamaños de vector 

    int main() 
    {  
        int i = 0;
        int maximo = 0;
        int minimo = 0;
        int array[N];  
        unsigned t0, t1;
 
        // Damos valores aleatorios al vector (entre 0 y 99) 
        srand (time(NULL)); // Semilla de números aleatorios 
        for (i = 0; i < N; i++) array[i] = rand()%100; 

        maximo = array[0];
        minimo = array[0];

        t0=clock();

        omp_set_num_threads(5);

        #pragma omp parallel for schedule(dynamic, 5)
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


        t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);

    
        printf("El máximo es el %d \n",maximo);
        printf("El mínimo es el %d \n",minimo);
        printf("Tiempo requerido: %0.15f\n",time);

        return 0;
    }
