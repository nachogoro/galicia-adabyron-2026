# Introducción a la solución

El problema pide determinar si una grada circular de columnas binarias (azules
y blancas) es **armoniosa**: formada por al menos dos franjas, todas del mismo
tamaño, alternando de color. Si lo es, hay que indicar el número de franjas;
si no, imprimir CELTA.

La dificultad principal es la **circularidad**: la primera y la última columna
son adyacentes y pueden pertenecer a la misma franja.

## Manejo de la circularidad

Para trabajar con la secuencia como si fuera lineal, primero hay que
neutralizar la frontera circular. Si el primer y el último elemento tienen el
mismo color, pertenecen a la misma franja, y por tanto la primera franja no
tiene su primer elemento en la primera posición. Para evitar partir esa franja
en dos:

1. Se rotan elementos del final al principio mientras el último y el primero
   coincidan en color. Tras este proceso, la primera franja empieza en la
   primera posición.

2. Si tras la rotación todos los elementos son del mismo color, solo hay una
   franja. Como se exigen al menos dos, se imprime CELTA.

## Conteo y validación de franjas

Una vez resuelta la circularidad, la secuencia empieza y termina con colores
distintos. Se recorre de izquierda a derecha contando franjas:

1. Se mide la longitud de la primera franja. Esta será la longitud de
   referencia.

2. Se recorren las franjas restantes. Cada vez que el color cambia, se
   verifica que la franja anterior que acaba de terminar tenga la misma
   longitud que la primera.

3. Si todas las franjas coinciden en longitud, se imprime el número de
   franjas. Si alguna difiere, se imprime CELTA.

## Complejidad

- **Tiempo:** $O(C)$ por caso de prueba.
- **Espacio:** $O(C)$ para almacenar la secuencia.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [J.cpp](src/J.cpp) | :x: |
