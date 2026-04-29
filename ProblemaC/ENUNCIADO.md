# Problema C - Portales del Laboratorio

En un laboratorio secreto de la Universidad hay $N$ salas conectadas por $M$ pasillos bidireccionales.
Cada pasillo conecta dos salas distintas y tarda 1 minuto en recorrerse. Algunas salas contienen
portales experimentales. Cada portal pertenece a un tipo identificado por un número entero entre
1 y $K$. Si una persona se encuentra en una sala con un portal de tipo $t$, puede teletransportarse
instantáneamente a cualquier otra sala con portal del mismo tipo. Sin embargo, por razones de
seguridad, cada tipo de portal solo puede utilizarse una vez durante todo el recorrido. Tu tarea es
determinar el mínimo tiempo necesario para ir desde la sala 1 hasta la sala $N$.

## Entrada

La primera línea de la entrada contiene tres enteros $N$, $M$ y $K$ ($1 \leq N \leq 2 \cdot 10^5$, $0 \leq M \leq 2 \cdot 10^5$, $1 \leq K \leq N$), que representan el número de salas, el número de pasillos y el número de tipos de portales,
respectivamente.

La segunda línea contiene $N$ enteros ($p_1\ p_2\ \cdots\ p_n$) que definen el tipo de portal para cada una de las
$N$ salas donde:

- $p_i = 0$ significa que la sala $i$ no tiene portal.
- $p_i = t$ ($1 \leq t \leq K$) significa que la sala $i$ tiene un portal del tipo $t$.

Las siguientes $M$ líneas contienen dos enteros $u\ v$, indicando un pasillo entre las salas $u$ y $v$.

## Salida

Se debe imprimir un único entero con el tiempo mínimo necesario para ir desde la sala 1 hasta la sala
$N$, o $-1$ si no es posible llegar.

## Entrada de ejemplo
```
6 5 2
1 0 2 1 0 2
1 2
1 2
2 3
3 4
4 5
5 6
```

## Salida de ejemplo
```
1
```
