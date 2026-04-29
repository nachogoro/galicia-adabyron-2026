# Problema D - Aceite

Una empresa tiene $n$ almazaras distribuidas en distintas localizaciones de una única ruta que pasa
por las localizaciones desde la 1 hasta la $n$. Las localizaciones $i$ e $i + 1$ son vecinas entre sí (para
$1 \leq i \leq n - 1$).

En la $i$-ésima almazara, la empresa cuentan con $x_i$ litros de aceite. La empresa desea movilizar sus
reservas de aceite para abastecer todas las localizaciones de las almazaras. En este sentido, se encargará
de movilizar el aceite de tal forma de que al finalizar el proceso, la almazara con la mínima cantidad
de aceite tenga tantos litros de aceite como sea posible.

La empresa moviliza el aceite en cubas, que están disponibles para transportar el aceite. Las cubas
están disponibles para realizar tantos viajes como sea necesario. Una cuba puede transportar en un
solo viaje cualquier cantidad entera de litros de aceite desde una almazara hasta otra vecina. En esos
viajes entre almazaras vecinas las cubas pierden aceite. Entre la $i$-ésima y la $(i + 1)$-ésima almazara
se pierden $c_i$ litros de aceite ($1 \leq i \leq n - 1$). La pérdida de aceite es la misma sin importar si la
cuba transporta aceite desde la almazara $i$ hasta la $i + 1$, o si realiza el viaje desde la almazara $i + 1$
hasta la $i$. En ambos casos, si la cuba viaja transportando $k$ litros de aceite de la almazara origen a
la almazara destino, llegarán solamente $k - c_i$ litros. Si $k \leq c_i$, no tiene sentido realizar el transporte
y por tanto, no se podrá hacer.

En este problema se pide calcular un valor entero positivo que será la máxima cantidad de litros de
aceite que quedarán en la almazara que tenga la menor cantidad de aceite al finalizar el proceso que
se habrá hecho de forma óptima para maximizar ese número.

## Entrada

La primera línea de la entrada contiene un entero positivo $n$ indicando el número de almazaras, siendo
$1 \leq N \leq 10000$.

En la segunda línea se encuentran $n$ números enteros positivos separados por espacios ($x_1\ x_2\ x_3\ \ldots\ x_n$)
representando cada $x_i$ los litros de aceite que hay en cada almazara, siendo $1 \leq x_i \leq 10^6$.

En la tercera línea se encuentran $n-1$ números enteros positivos separados por espacios ($c_1\ c_2\ c_3\ \ldots\ c_{n-1}$)
de forma que cada $c_i$ la pérdida de aceite que se produce al transportar aceite entre las localizaciones
$i$ y $i + 1$ y con independencia del sentido del viaje, siendo $1 \leq c_i \leq (x_i + x_{i+1})$.

## Salida

Valor entero positivo que será la máxima cantidad de litros de aceite que quedarán en la almazara que
tenga la menor cantidad de aceite al finalizar el proceso, asumiendo que el mismo se realiza de manera
óptima.

## Entrada de ejemplo 1
```
2
3 1
1
```

## Salida de ejemplo 1
```
1
```

## Entrada de ejemplo 2
```
2
20 18
10
```

## Salida de ejemplo 2
```
18
```

## Entrada de ejemplo 3
```
3
10 51 10
5 6
```

## Salida de ejemplo 3
```
20
```
