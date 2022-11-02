
# ANÁLISIS DE LOS RESULTADOS OBTENIDOS SEGÚN LA VERSIÓN

Tras la creación y ejecución tanto del programa que resuelve el problema de forma secuencial como paralelizada, se llega a la conclusión de que para un caso como éste, resulta más eficiente el primero de ellos.

Con el **programa secuencial** se obtienen tiempos de alrededor a 0.000004000000000 segundos aproximadamente.
Sin embargo, con el **paralelizado**, una **peor marca**: 0.000269000000000 segundos aproximadamente.

Es importante explicar que para llegar a la versión paralelizada del programa secuencial simplemente se emplean 2 tipos de directivas omp:

* **#pragma omp parallel for schedule(dynamic, 5)**: ayuda a paralelizar estructuras iterativas como lo es el bucle for que la acompaña. Además, utilizamos la opción de dividir el trabajo en partes de igual tamaño (en este caso de 5 en 5) para que se les asignaran a los hilos libres de manera dinámica.

* **#pragma omp critical**: permite que los bloques condicionales if que la acompañan sean tratados como una sección crítica. Así, el valor de la variable "máximo" y "mínimo" serán modificadas y leídas de forma controlada, evitando problemas de coherencia.



