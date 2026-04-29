# Introducción a la solución

El problema pide eliminar repetidamente pares de dígitos consecutivos iguales
de una secuencia, incluyendo las eliminaciones en cascada que se producen
cuando, al quitar un par, los dígitos adyacentes que quedan resultan ser
iguales.

Este proceso es exactamente el comportamiento de una **pila** (stack).

## Resolución con pila

Se recorre la secuencia de dígitos de izquierda a derecha. Para cada dígito
se compara con el tope de la pila:

1. Si la pila está vacía o el tope es distinto del dígito actual, se hace
   **push** del dígito.
2. Si el tope coincide con el dígito actual, se hace **pop** — ambos dígitos
   se eliminan mutuamente.

Las eliminaciones en cascada se manejan de forma natural: al hacer pop de un
par, el siguiente dígito de la entrada se compara con el nuevo tope de la
pila, que a su vez podría coincidir y provocar otra eliminación. La pila
mantiene en todo momento el estado correcto de la secuencia tras todas las
eliminaciones posibles hacia la izquierda.

Al terminar de procesar todos los dígitos, la pila contiene la combinación
secreta. Si queda vacía, la combinación es 0.

## Complejidad

- **Tiempo:** $O(M)$ por caso de test, donde $M$ es la longitud de la
  secuencia. Cada dígito se procesa exactamente una vez (un push y como
  mucho un pop).
- **Espacio:** $O(M)$ para la pila.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [G.cpp](src/G.cpp) | :x: |
