# Problema G - Bóveda de los duplicados

En una antigua base secreta existe una **bóveda digital** que protege un valioso tesoro. La bóveda
solo se abre introduciendo la **combinación correcta de números**. El problema es que el sistema
de seguridad está defectuoso: cuando se generó la combinación original, el programa añadió **números
duplicados consecutivos por error**.

Los ingenieros descubrieron una pista en el sistema: "*La verdadera combinación se obtiene eliminando
cada par de números consecutivos iguales. Cada vez que aparezcan dos números iguales seguidos,
ambos desaparecen.*"

Pero hay un detalle importante: cuando se eliminan dos números, **los números que quedan pueden
juntarse y formar nuevos duplicados**, que también deben eliminarse. El proceso continúa **hasta
que ya no queden números consecutivos iguales**.

Si se eliminan todos los números la combinación secreta será el 0. La secuencia final será **la combinación secreta que abre la bóveda**.

## Entrada

La primera línea de la entrada contiene un entero positivo $N$ ($1 \leq N \leq 1500$) indicando el número de
combinaciones de test.

Las siguientes $N$ líneas contienen una secuencia de dígitos cuya longitud es $M$ ($2 \leq M \leq 10000$). Cada
dígito puede tomar valores entre 1 y 9.

## Salida

Combinación secreta que abre la bóveda, es decir, N líneas con una secuencia de elementos sin dígitos
consecutivos iguales. Se recuerda que puede haber líneas con el valor 0, es el caso en que se eliminan
todos los dígitos.

## Entrada de ejemplo
```
5
1122334455667788899
1234554321
4556677899987766
123444433221
987665544332211234455
```

## Salida de ejemplo
```
0
0
4898
1231
98723
```
