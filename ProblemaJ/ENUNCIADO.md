# Problema J - Blanquiazul

Las gradas de los estadios de fútbol se consideran **armoniosas** si siguen un patrón específico de colores:
están formadas por franjas de columnas de sillas azules y blancas, que alternan en color, y todas las
franjas tienen exactamente el mismo ancho.

Una grada se describe mediante una secuencia de valores binarios:

- 1 representa una columna de sillas azules.
- 0 representa una columna de sillas blancas.

Se denomina franja a una secuencia máxima de columnas consecutivas del mismo color. Además,
la grada es **circular**: después de la última columna, la siguiente es la primera, por lo que deben
considerarse consecutivas. En particular, si ambas tienen el mismo color, pertenecen a la misma
franja.

Se dice que una grada es armoniosa si:

- Tiene al menos dos franjas.
- Todas las franjas están compuestas por exactamente el mismo número de columnas.

Dada la descripción de varias gradas, tu tarea es determinar si cada una de ellas es armoniosa. En caso
afirmativo, debes indicar el número total de franjas en la grada. En caso contrario, debes imprimir
CELTA.

## Entrada

La primera línea contiene un entero $N$ ($1 \leq N \leq 100$), el número de casos de prueba.

Cada caso de prueba consta de dos líneas:

- La primera contiene un entero $C$ ($1 \leq C \leq 20$), el número de columnas de la grada.
- La segunda contiene $C$ enteros separados por espacios (un espacio entre cada par de enteros),
  cada uno igual a 0 o 1, describiendo la grada.

## Salida

Para cada caso de prueba, escribe por salida estándar una línea con:

- El número de franjas si la grada es armoniosa.
- CELTA en caso contrario.

## Entrada de ejemplo
```
6
4
1 0 1 0
5
1 1 0 0 0
3
1 1 1
6
1 0 0 1 1 0
6
1 1 0 0 1 1
6
1 0 0 0 1 1
```

## Salida de ejemplo
```
4
CELTA
1
CELTA
CELTA
2
```
