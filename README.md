# Ordenador automático de videojuegos
Este proyecto tiene como propósito ordenar videojuegos por orden alfabético, fecha de estreno, rating o precio. Mi inspiración para este código fue la plataforma de videojuegos Steam, pues usa un método similar para ordenar sus videojuegos.

## SICT0301: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

Función para ordenar: En la mayoría de los casos la complejidad de tiempo será Θ(n^2), pues se usa el algoritmo bubble sort. En el caso que ya se encontraran ordenados los datos, se tardaría Ω(n). En cuanto a la complejidad de espacio, será O(1)

## SICT0302: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Para este problema utilicé el algoritmo de bubble sort para poder organizar los videojuegos de acorde a su fecha, nombre, rating o precio. Elegí este algoritmo pues fue con el que más cómodo me sentí al programar, pero es probable que en futuras actualizaciones del programa use un algoritmo más complejo para optimizar el tiempo. Se puede ver usado en las funciones del archivo Juego.h en las líneas 55, 68, 81 y 94.
