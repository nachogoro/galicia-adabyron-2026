# Introducción a la solución

El problema nos pide localizar la posición $(x_0, y_0)$ del volcán en una
matriz $n \times n$, realizando consultas de temperatura. La temperatura en
cada celda es $T(x, y) = C - (|x - x_0| + |y - y_0|)$, donde $C$ es una
constante desconocida. El número máximo de consultas permitido es $5n$.

La clave está en la estructura de la función de temperatura: depende de la
distancia Manhattan al volcán, y esta distancia se descompone como suma de
dos términos independientes, uno en cada eje.

## Descomposición por ejes

Si fijamos $y = 0$, la temperatura se reduce a:

$$T(x, 0) = C - |x - x_0| - y_0$$

Los términos $C$ y $y_0$ son constantes, por lo que $T(x, 0)$ se maximiza
exactamente cuando $|x - x_0|$ se minimiza, es decir, cuando $x = x_0$.
Lo mismo ocurre en el otro eje: fijando $x = 0$,
$T(0, y) = C - x_0 - |y - y_0|$ se maximiza cuando $y = y_0$.

## Algoritmo

1. Se recorren todas las posiciones $x$ de $0$ a $n - 1$ con $y = 0$,
   consultando $T(x, 0)$. Se guarda el $x$ con la temperatura más alta:
   ese es $x_0$.

2. Se repite el proceso recorriendo todas las posiciones $y$ de $0$ a $n - 1$
   con $x = 0$, consultando $T(0, y)$. El $y$ con la mayor temperatura es
   $y_0$.

3. Se reporta la posición $(x_0, y_0)$.

Se realizan exactamente $2n$ consultas, dentro del límite de $5n$.

## Complejidad

- **Consultas:** $2n$
- **Tiempo:** $O(n)$

## Opcional: búsqueda ternaria

La solución lineal funciona, pero se puede reducir drásticamente el número
de consultas aprovechando que $T(x, 0)$ no solo tiene un máximo en $x_0$,
sino que es **unimodal**: crece estrictamente hasta $x_0$ y decrece
estrictamente después. Esto permite aplicar búsqueda ternaria en lugar de
un escaneo completo.

La búsqueda ternaria divide el intervalo $[lo, hi]$ en tres partes iguales
mediante dos puntos $m_1$ y $m_2$, y consulta la temperatura en ambos:

- Si $T(m_1) < T(m_2)$, el máximo está a la derecha de $m_1$: se descarta
  el tercio izquierdo.
- Si $T(m_1) \geq T(m_2)$, el máximo está a la izquierda de $m_2$: se
  descarta el tercio derecho.

En cada iteración el intervalo se reduce por un factor de $\frac{2}{3}$,
hasta que queden 2-3 posiciones que se comprueban directamente.

Se aplica una vez para encontrar $x_0$ (fijando $y = 0$) y otra para $y_0$
(fijando $x = 0$).

### Complejidad

- **Consultas:** $\sim 2 \cdot \lceil\log_{3/2} n\rceil$. Para $n = 1000$,
  unas 36 consultas frente a las 2000 de la versión lineal.
- **Tiempo:** $O(\log n)$

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [A_linear.cpp](src/A_linear.cpp) | :x: |
| [A_ternary.cpp](src/A_ternary.cpp) | :x: |
