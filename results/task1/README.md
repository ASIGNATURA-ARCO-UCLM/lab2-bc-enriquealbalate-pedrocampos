
# ANÁLISIS DE LOS RESULTADOS OBTENIDOS SEGÚN LA VERSIÓN

Tras la creación y ejecución del programa secuencial y de ambas versiones de la versión paralelizada, se llega a la conclusión de que para ambos casos resulta más eficiente la versión secuencial.

Con el **programa secuencial** se obtienen tiempos de alrededor a 0.000003000000000 segundos aproximadamente.
Sin embargo, con el **paralelizado**, una **peor marca**: 0.000261000000000 segundos aproximadamente en ambas versiones.

Para la primera versión (**maximo_minimo_paralelizadoV1**) hemos usado las siguientes directivas:

* **#pragma omp for schedule(dynamic, 10)**: ayuda a paralelizar estructuras iterativas como lo es el bucle for que la acompaña. Además, utilizamos la opción de dividir el trabajo en partes de igual tamaño (en este caso de 10 en 10) para que se les asignaran a los hilos libres de manera dinámica.

* **#pragma parallel omp critical**: permite que los bloques condicionales if que la acompañan sean tratados como una sección crítica. Así, el valor de la variable "máximo" y "mínimo" serán modificadas y leídas de forma controlada, evitando problemas de coherencia. Por ejemplo podría ocurrir que dos hilos comprobasen de forma satisfactoria que el número que manejan supera al valor de la variable "maximo", y por lo tanto decidan sobreescribirla. Esto daría la posibilidad de que, aunque un hilo cuente con un número superior al del otro, se asigne el menor a la variable usada debido a que esa operación quede ordenada por la cpu después de la asignación del número correcto.

Y para la segunda versión (**maximo_minimo_paralelizadoV2**) hemos añadido el uso de:

* **#pragma omp parallel sections** y **#pragma omp section**: donde se definen las secciones de codigo que se va a dividir entre varios hilos (cada hilo ejecuta una sección).

Por último, cabe destacar que se detecta una **correspondencia entre el aumento de hilos creados por el programa y el tiempo** destinado a su ejecución. De esa forma, si sólo se genera un único hilo, dicho intervalo temporal se reduciría al mínimo, el del programa secuencial. Por otro lado, en este caso resulta un poco más veloz el programa paralelizado en la segunda versión presentada que en la primera, a pesar del empleo de secciones.

