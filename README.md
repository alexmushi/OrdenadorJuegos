# Ordenador de videojuegos
Este proyecto tiene como propósito ordenar videojuegos extraídos de un archivo .csv por orden alfabético, fecha de estreno, rating o precio. También se pueden buscar juegos por atributos en específico, y de igual manera se pueden guardar ya ordenados por la opción elegida por el usuario en un archivo .csvMi inspiración para este código fue la plataforma de videojuegos Steam, pues usa un método similar para ordenar sus videojuegos. 

## SICT0301: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

bubble_texto y bubble_num: En la mayoría de los casos la complejidad de tiempo será O(n^2), pues se usa el algoritmo bubble sort. En el caso que ya se encontraran ordenados los datos, se tardaría Ω(n). En cuanto a la complejidad de espacio, será O(1)

### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa

agrega_juego: La inserción al final de una lista doblemente enlazada es constante, O(1).
menu_busqueda y busqueda: Se usa búsqueda binaria, se aproxima a O(log N).

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

getters: O(1), son accesos simples.
toString_juegos: O(n), pues se recorre la lista una vez.
toString_elemento: O(1). Es constante debido a que llama a la función formato_juego, la cual realiza operaciones de concatenación.
toString_atributo: O(n), pues igual recorre una vez la lista.
letra_numero: O(1). Es constante, ya que sólo son ifs y getters
generar_archivo: O(n), pues se realiza un bucle que recorre todos los elementos de la lista para escribir.

## SICT0302: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Para este problema utilicé el algoritmo de bubble sort para poder organizar los videojuegos de acorde a su fecha, nombre, rating o precio. A pesar de que en el peor de los casos puede tardarse O(n^2), es un algoritmo bastante confiable y simple de implementar.. Se puede ver usado en las funciones del archivo Juego.h bubble_texto y bubble_num.

### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.

Se usó una lista doblemente ligada para guardar la información del proyecto pues facilita varias operaciones como la inserción, y se usa para poder ordenar los Juegos de acuerdo a lo que quiera el usuario.

## SICT0303: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructras correctos

Para consultar información, se usaron las funciones menu_busqueda y busqueda para que el usuario ingrese un valor que quiera buscar en los juegos de la lista (ya sea nombre, calificación, precio o año de estreno)

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta

Se lee un archivo que contiene los juegos iniciales a través de la función leer_archivo, la cual usa un archivo .csv para importar la información necesaria.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta

Para guardar los datos se usa la función generar_archivo, la cual guarda en un nuevo archivo .csv los juegos como los dejó el usuario, ya sea ordenados o con juegos extra.

