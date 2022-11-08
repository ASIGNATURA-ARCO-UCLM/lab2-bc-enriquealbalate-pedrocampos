# ANÁLISIS DE EJECUCIONES

De nuevo, en esta ocasión se detecta fácilmente cómo el programa secuencial resulta más veloz que el paralelizado. 

A su vez, al existir en el código de "pi.cpp" un bluce del tipo "for", decidimos que la mejor forma de paralelizarlos sería mediante la directiva **#pragma omp parallel for**, pues así openMP se encarga de generar una serie de hilos a los cuales les encomienda la ejecución de una cantidad determinada de sus iteraciones.

Por otro lado, dentro del propio bucle inicialmente barajamos la posibilidad de emplear la directiva **pragma omp critical** para marcar las dos instrucciones que contiene como una sección crítica (utilizado en **pi_paralelizado_V1**). Sin embargo, caímos en la cuenta de que podría usarse la directiva **#pragma omp atomic**, que reduce el coste temporal y provoca menos esperas entre los hilos (utilizado en **pi_paralelizado_V2**). El argumento que nos hizo tener esa idea fue que, en este caso, bastaba con controlar que no se escribiera simultáneamente sobre la variable "sum" ni "xi" para que el cálculo del número pi fuera exitoso (no era necesario bloquear el paso de los hilos dentro del bucle si otro ya había entrado en él).

De igual manera, no se aprecian mejoras significativas en los tiempos de ejecución de la segunda versión frente a la primera.