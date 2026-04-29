# Introducción a la solución

El problema pide contar cuántas subsecuencias contiguas de una secuencia de
enteros son **armoniosas**, es decir, tales que todo par de elementos
distintos en la subsecuencia tiene MCD igual a 1.

Una subsecuencia de un solo elemento siempre es armoniosa, y las
subsecuencias más largas exigen que no haya ningún par con factor común
mayor que 1.

La propiedad clave para resolverlo de forma eficiente es que si una
subsecuencia $A[l..r]$ es armoniosa, también lo es cualquier sub-subsecuencia
$A[l'..r']$ con $l \leq l' \leq r' \leq r$. En otras palabras: acortar una
subsecuencia armoniosa nunca rompe la armonía. Esto permite usar la técnica
de **ventana deslizante** (two pointers).

## Ventana deslizante con producto acumulado

Se mantiene una ventana $[l, r)$ que representa la subsecuencia armoniosa
más larga que empieza en $l$. Para verificar si un nuevo elemento $A[r]$
es compatible con todos los de la ventana, se utiliza un **producto
acumulado** $p$ de los elementos en ella.

La idea es que si todos los pares dentro de la ventana tienen MCD 1, entonces
$\gcd(p, A[r]) = 1$ implica que $A[r]$ no comparte factores con ninguno de
los elementos en la ventana, y se puede extender.

El algoritmo:

1. Empezamos con $l = r = 0$ y $p = 1$.
2. Si $\gcd(p, A[r]) = 1$: el elemento es compatible. Multiplicamos $p$ por
   $A[r]$ y avanzamos $r$.
3. En caso contrario: contamos las $r - l$ subsecuencias armoniosas que
   empiezan en $l$ (las que terminan en $l, l+1, \ldots, r-1$), dividimos $p$
   entre $A[l]$ y avanzamos $l$.

Cada puntero avanza como máximo $N$ veces, por lo que la complejidad es
lineal en el número de operaciones de GCD.

El problema de esta solución es que el producto $p$ crece sin límite: con
elementos de hasta $10^6$ y ventanas potencialmente largas, desborda
cualquier tipo entero de C++. En Python funciona gracias a la aritmética de
precisión arbitraria, pero a costa de rendimiento.

## Complejidad

- **Tiempo:** $O(N \log(\max(A_i)))$ por las operaciones de GCD, pero cada
  GCD se calcula sobre números de precisión arbitraria cuyo tamaño crece
  con la ventana, así que el coste real es mayor.
- **Espacio:** $O(1)$ adicional (sin contar la entrada).

## Ventana deslizante con mapa de factores primos

Para evitar el producto gigante, se puede sustituir por un **mapa de
factores primos** presentes en la ventana. La condición de armonía (todos
los pares con MCD 1) equivale a que ningún primo aparezca en más de un
elemento de la ventana. Esto se puede verificar con un mapa que asocie cada
primo a la posición del elemento que lo introdujo.

### Criba de menor factor primo (SPF)

Se precalcula una criba hasta $10^6$: para cada número, su menor factor
primo. Esto permite factorizar cualquier $A_i$ en $O(\log A_i)$ dividiendo
sucesivamente por el menor factor primo.

### Algoritmo

Se avanza el puntero derecho $r$ elemento a elemento. Para cada $A[r]$:

1. Se factoriza $A[r]$ y se busca en el mapa si alguno de sus primos ya
   está presente. Si hay conflicto, se registra la posición más reciente
   entre los elementos conflictivos.

2. Se avanza el puntero izquierdo $l$ hasta pasar el conflicto, eliminando
   del mapa los primos de cada elemento que sale de la ventana.

3. Se registran los primos de $A[r]$ en el mapa con posición $r$.

4. Se suman $r - l + 1$ subsecuencias (todas las que terminan en $r$ y
   empiezan en algún punto de $[l, r]$).

### Complejidad

- **Tiempo:** $O(N \cdot \omega(\max A_i) + \max A_i)$, donde
  $\omega(\max A_i)$ es el número de factores primos distintos (como mucho
  7 para valores hasta $10^6$). La criba cuesta $O(\max A_i)$.
- **Espacio:** $O(N + \max A_i)$ para la criba y las factorizaciones.

Esta versión funciona en C++ sin problemas de desbordamiento.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [E.py](src/E.py) | Two pointers con producto acumulado | :x: |
| [E.cpp](src/E.cpp) | Two pointers con mapa de factores primos (criba SPF) | :x: |
