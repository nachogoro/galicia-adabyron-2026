# Introducción a la solución

El problema pide calcular el número mínimo de vigilantes necesarios para
cubrir a todos los equipos, donde cada vigilante colocado en una posición $p$
cubre el rango $[p - K, p + K]$.

## Algoritmo greedy

La idea es recorrer los equipos en orden de posición y, cada vez que
encontremos un equipo no cubierto, colocar un vigilante de la forma más
eficiente posible: lo más a la derecha que se pueda sin dejar descubierto a
ese equipo.

1. Ordenar los puestos ocupados de menor a mayor.
2. Mantener una variable `cubierto_hasta` que indica hasta qué puesto llega
   la cobertura del último vigilante colocado. Inicialmente no hay cobertura.
3. Para cada equipo en orden:
   - Si su puesto ya está cubierto (`puesto ≤ cubierto_hasta`), no hace falta
     hacer nada.
   - Si no está cubierto, se coloca un nuevo vigilante. La posición óptima
     es $p + K$ (donde $p$ es el puesto del equipo), lo que maximiza la
     cobertura hacia la derecha: cubre desde $p$ hasta $p + 2K$.
     Se actualiza `cubierto_hasta = p + 2K`.

### Justificación de optimalidad

En el momento en que un equipo no está cubierto, es obligatorio colocar al
menos un vigilante más. Colocarlo en $p + K$ es la mejor opción porque
cualquier posición más a la izquierda cubriría ese equipo pero dejaría de
cubrir posiciones a la derecha que podría haber alcanzado, y cualquier
posición más a la derecha no cubriría al equipo en cuestión.

## Complejidad

- **Tiempo:** $O(E \log E)$ por caso de test, dominado por la ordenación.
  El recorrido posterior es $O(E)$.
- **Espacio:** $O(E)$

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [I.cpp](src/I.cpp) | :x: |
