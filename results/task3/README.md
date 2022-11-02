# ANÁLISIS DE EJECUCIONES

De nuevo, en esta ocasión se detecta fácilmente cómo el programa secuencial resulta más veloz que el paralelizado. 

A su vez, al existir en el código de "pi.cpp" un bluce del tipo "for", decidimos que la mejor forma de paralelizarlos sería mediante la directiva **#pragma omp parallel for**, pues así el openMP se encarga de generar una serie de hilos a los cuales les encomienda la ejecución de una cantidad determinada de sus iteraciones.

Por otro lado, dentro del propio bucle inicialmente barajamos la posibilidad de emplear la directiva **pragma omp critical** para marcar las dos instrucciones que contiene como una sección crítica. Sin embargo, caímos en la cuenta de que podría usarse la directiva **#pragma omp atomic**, que reduce el coste temporal y provoca menos esperas entre los hilos. El argumento que nos hizo cambiar de idea fue el hecho de que en este caso bastaba con controlar que no se escribiera simultáneamente sobre la variable "sum" ni "xi" para que el cálculo del número pi fuera exitoso (no era necesario bloquear el paso de los hilos dentro del bucle si otro ya había entrado en él).