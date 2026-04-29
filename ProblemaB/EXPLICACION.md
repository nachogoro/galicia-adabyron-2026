# Introducción a la solución

El problema pide determinar si en una línea de texto existe una palabra
**dominante** (una que aparece estrictamente más veces que todas las demás).
Si dos o más palabras comparten la frecuencia máxima, se imprime "empate".

Se trata de un problema de conteo de frecuencias directo, resoluble en una
sola pasada por la entrada.

## Algoritmo

Se mantiene un diccionario que asocia cada palabra con su número de
apariciones, y dos variables auxiliares: la frecuencia máxima vista hasta el
momento y la palabra candidata a dominante.

Al procesar cada palabra:

1. Se incrementa su frecuencia en el diccionario.
2. Si la nueva frecuencia supera el máximo actual, la palabra pasa a ser la
   nueva candidata y se actualiza el máximo.
3. Si iguala el máximo sin ser la candidata actual, se marca que hay empate
   (la candidata se invalida).

Al final, si existe una candidata válida se imprime; en caso contrario se
imprime "empate".

## Complejidad

- **Tiempo:** $O(S)$, donde $S$ es el número de palabras.
- **Espacio:** $O(S)$ para el diccionario de frecuencias.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [B.cpp](src/B.cpp) | :x: |
