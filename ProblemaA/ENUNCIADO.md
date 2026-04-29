# Problema A - Volcán en la FIX

En la facultad de informática de tu universidad (la legendaria FIX) han detectado un problema...
peculiar. Como es tradición ante cualquier incidencia (desde caídas de la red WiFi hasta inofensivas
amenazas de bomba), se ha avisado a Mr. T, **Vicedecano de Infraestructuras**, para que se encargue
de la situación.

Tras una breve inspección, y varias miradas de preocupación, se ha determinado que el problema
podría estar relacionado con una actividad organizada entre **Delegación de Alumnos** y el **GPUL**,
donde alguien decidió instalar un "simulador volcánico experimental" en algún punto de la FIX.
Naturalmente, nadie recuerda dónde lo dejaron. Desde entonces, la temperatura en la facultad se ha
vuelto inusualmente alta. Más incluso que en las aulas del ala sur en plena época de exámenes.

La facultad se puede modelar como un *grid* (matriz) de tamaño $n \times n$. Existe una única celda $(x_0, y_0)$
donde se encuentra el dispositivo (también conocido como "el volcán"). La temperatura en cada celda
$(x, y)$ está dada por:

$$T(x, y) = C - (|x - x_0| + |y - y_0|)$$

donde $C$ es una constante (desconocida para ti) suficientemente grande para que las temperaturas en
todas las celdas sean positivas.

Es decir, cuanto más cerca estés del volcán, más calor hace (y más probable es que alguien esté ejecutando
código sin optimizar). Cuando estás en la celda donde se encuentra el volcán, la temperatura
es exactamente $C$.

Tu tarea es encontrar la ubicación del volcán realizando consultas sobre celdas de la matriz.
Para cada consulta, el sistema te devolverá la temperatura en la celda elegida.

Cuando estés seguro de la ubicación del volcán, debes reportar su posición y terminar el programa.

Se garantiza que existe exactamente una celda con temperatura máxima $C$.

**Nota:** La temperatura depende únicamente de la distancia Manhattan al volcán.

**Importante:** Este es un problema interactivo. Debes refrescar la salida después de cada escritura
(lo que se conoce como hacer *flush*). Por ejemplo:

- En C: `fflush(stdout)`
- En C++: `cout << endl` o `cout << flush`
- En Java: `System.out.flush()`
- En Python: `stdout.flush()` o `print(..., flush=True)`

## Entrada

La primera línea contiene un entero $n$ ($1 \leq n \leq 1000$), el tamaño de la matriz, que debes leer de
entrada estándar. La interacción comienza inmediatamente después de leer este valor.

## Salida

Al ser un problema interactivo, para realizar una consulta sobre una celda $(x, y)$, debes escribir por la
salida estándar (de la misma forma que en cualquier otro problema):

```
? x y
```

Donde x, y son las coordenadas de la celda que quieres consultar: $0 \leq x, y \leq n - 1$, x es la coordenada
horizontal en el sentido de izquierda a derecha y y es la coordenada vertical en el sentido de abajo a
arriba ($$(0, 0)$$ es la esquina inferior izquierda y $$(n - 1, n - 1)$$ es la esquina superior derecha).

**Importante:** Después de escribir la consulta, debes hacer *flush* de la salida.

A continuación, leerás de la entrada estándar (de la misma forma que en cualquier otro problema) un
entero que representa el valor de $T(x, y)$.

**Puedes realizar como máximo $5n$ consultas**. En caso de que excedas este número, o realices una
consulta inválida, leerás como respuesta a $T(x, y)$ un $-1$ y tu programa debe terminar inmediatamente.

Cuando determines la posición del volcán, debes imprimir:

```
! x y
```

Después de imprimir la respuesta final, debes hacer *flush* y terminar el programa.

## Ejemplos de Entrada y Salida

A continuación se muestra un ejemplo de interacción. Supongamos que el volcán se encuentra en la
celda $(3, 3)$ y que $C = 10$.

| Juez | Programa | Comentario |
| :--: | :------: | :--------- |
| 5    |          | El juez envía el tamaño de la matriz, $n = 5$. |
|      | ? 1 1    | El programa consulta la celda $(1, 1)$. |
| 6    |          | $|1 - 3| + |1 - 3| = 4$, luego $T(1, 1) = 10 - 4 = 6$. |
|      | ? 2 2    | El programa consulta la celda $(2, 2)$. |
| 8    |          | $|2 - 3| + |2 - 3| = 2$, luego $T(2, 2) = 10 - 2 = 8$. |
|      | ? 3 3    | El programa consulta la celda $(3, 3)$. |
| 10   |          | $|3 - 3| + |3 - 3| = 0$, luego $T(3, 3) = 10$. |
|      | ! 3 3    | El programa determina correctamente la posición del volcán. |

**Nota:** Esto es solo un ejemplo de interacción. No necesariamente tiene que existir un programa que
resuelva el problema realizando exactamente esas consultas.
