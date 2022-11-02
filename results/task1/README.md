
# ANÁLISIS DE LOS RESULTADOS OBTENIDOS SEGÚN LA VERSIÓN

Tras la creación y ejecución tanto del programa que resuelve el problema de forma secuencial como paralelizada, se llega a la conclusión de que para un caso como éste, resulta más eficiente el primero de ellos.

Con el **programa secuencial** se obtienen tiempos de alrededor a 0.000003000000000 segundos aproximadamente.
Sin embargo, con el **paralelizado**, una **peor marca**: 0.000261000000000 segundos aproximadamente.

Es importante explicar que para llegar a la versión paralelizada del programa secuencial simplemente se emplean 2 tipos de directivas omp:

* **#pragma omp for schedule(dynamic, 5)**: ayuda a paralelizar estructuras iterativas como lo es el bucle for que la acompaña. Además, utilizamos la opción de dividir el trabajo en partes de igual tamaño (en este caso de 5 en 5) para que se les asignaran a los hilos libres de manera dinámica.

* **#pragma parallel omp critical**: permite que los bloques condicionales if que la acompañan sean tratados como una sección crítica. Así, el valor de la variable "máximo" y "mínimo" serán modificadas y leídas de forma controlada, evitando problemas de coherencia. Por ejemplo podría ocurrir que dos hilos comprobasen de forma satisfactoria que el número que manejan supera al valor de la variable "maximo", y por lo tanto decidan sobreescribirla. Esto daría la posibilidad de que, aunque un hilo cuente con un número superior al del otro, se asigne el menor a la variable usada debido a que esa operación quede ordenada por la cpu después de la asignación del número correcto.

Por último, cabe destacar que se detecta una **correspondencia entre el aumento de hilos creados por el programa y el tiempo** destinado a su ejecución. De esa forma, si sólo se genera un único hilo, dicho intervalo temporal se reduciría al mínimo, el del programa secuencial.

