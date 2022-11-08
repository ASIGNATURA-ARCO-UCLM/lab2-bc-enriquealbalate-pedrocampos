 Para esta tarea hemos realizado dos soluciones, para ambas versiones hemos cambiado el tamaño del vector a 10 y hemos creado 5 hilos. En relación con el programa secuencial ambas versiones devolvian tiempos mayores.
 
 En cuanto al desarrollo de ambas versiones, para la primera de ellas en todos los bucles for hemos utilizado la sentencia **#pragma parallel for** para que cada hilo hiciera 2 iteraciones (5 hilos) y a la hora del cálculo del sumatorio hemos usado **#pragma omp atomic**. Y para la segunda versión lo que hemos incorporado es el uso de secciones para imprimir los resultados lo que ha generado peores resultados con respecto a la primera versión.
 
