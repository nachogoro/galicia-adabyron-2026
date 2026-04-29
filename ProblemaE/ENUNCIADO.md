# Problema E - Colorinchos

En el reino de Colorinchos, cada color está representado por un número entero positivo. Dos colores
se consideran incompatibles si comparten algún divisor mayor que 1. En cambio, si su máximo común
divisor es 1, pueden convivir sin problemas.

El consejo real quiere exhibir una secuencia continua de colores en una galería. Sin embargo, la
exhibición será considerada armoniosa solo si cada par de colores distintos dentro de la secuencia es
compatible, es decir, si su máximo común divisor es 1.

Dada la secuencia de colores, tu tarea es contar cuántas subsecuencias continuas son armoniosas.

Formalmente, una subsecuencia $A[l..r]$ es armoniosa si para todo par de posiciones distintas $(i, j)$ con
$l \leq i < j \leq r$ se cumple que: $mcd(A[i], A[j]) = 1$. Debes contar cuántas subsecuencias armoniosas
existen.

## Entrada

La primera línea contiene un entero $N$, la cantidad de colores.

La segunda línea contiene $N$ ($1 \leq N \leq 2 \times 10^5$) enteros $A_1, A_2, \ldots, A_N$, donde $A_i$ ($1 \leq A_i \leq 10^6$)
representa el valor asociado al color $i$.

## Salida

Imprime un único entero: la cantidad de subsecuencias válidas.

## Entrada de ejemplo 1
```
3
2 3 4
```

## Salida de ejemplo 1
```
5
```

## Entrada de ejemplo 2
```
4
2 6 5 7
```

## Salida de ejemplo 2
```
7
```
