 Aquí está el código que ha resultado después de la paralelización del código, donde hemos creado 2 hilos que se van a repartir el trabajo.
 En los bucles for hemos puesto la sentencia **omp parallel for** para que cada hilo realice 5 iteraciones (en este caso) porque hemos cambiado
 el valor de N a 10. En el bucle for donde se calcula el sumatorio hemos añadido además la sentencia **#pragma omp atomic** porque se modifica
 una zona de memoria.
 
 El resultado de hacer esto es que el programa secuencial corre más rapido que el paralelizado

   
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

        omp_set_num_threads(2);
        // Damos valores aleatorios al vector (entre 0 y 99)
        srand (time(NULL)); // Semilla de números aleatorios
        #pragma omp parallel for
            for (i = 0; i < N; i++) {
                v[i] = rand()%100;
            }

        // Cálculo del sumatorio
        #pragma omp parallel for
            for (i = 0; i < N; i++)
                #pragma omp atomic
                    sum += v[i];

        printf("\nVector de números: \n ");
        #pragma omp parallel for
            // Como comprobación, se visualizan los valores del vector y la suma
            for (i = 0; i < N; i++) printf("%d \t",v[i]);

        printf("\n La suma es: %d \n\n", sum);

        return 0;
    }
