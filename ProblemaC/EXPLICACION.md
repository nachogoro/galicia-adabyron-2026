# Introducción a la solución

El problema pide encontrar el camino más corto desde la sala 1 hasta la sala
$N$ en un grafo donde los pasillos cuestan 1 minuto y la teletransportación
entre salas con portales del mismo tipo es instantánea.

La observación clave es que las salas conectadas por portales del mismo tipo
forman, a efectos de distancia, un único "super-nodo": si estoy en cualquiera
de ellas puedo llegar instantáneamente a todas las demás del mismo tipo. Esto
sugiere contraer el grafo antes de buscar el camino.

El enunciado indica que cada tipo de portal solo puede usarse una vez durante
el recorrido. Antes de plantear la contracción, conviene ver que esta
restricción nunca es activa en un camino óptimo. Supongamos que un camino
usa portales de tipo $t$ dos veces: primero se teletransporta desde la sala
$A$ hasta la sala $B$, y más adelante desde la sala $C$ hasta la sala $D$
(todas con portal $t$). Pero entonces, en el primer uso podríamos habernos
teletransportado directamente desde $A$ hasta $D$, eliminando todo el tramo
intermedio entre $B$ y $C$. El camino resultante es al menos igual de corto
y solo usa el portal de tipo $t$ una vez. Por tanto, siempre existe un
camino óptimo que respeta la restricción de uso único, y podemos ignorarla
al buscar la solución.

## Contracción de nodos por tipo de portal

Se construye un nuevo grafo donde todas las salas que comparten un mismo tipo
de portal $t$ se fusionan en un único vértice. Las salas sin portal conservan
su propio vértice.

Concretamente:

1. Se recorre cada sala. Si tiene portal de tipo $t$ y es la primera sala con
   ese tipo, se crea un vértice nuevo para el tipo $t$. Si ya existe, se
   reutiliza. Si no tiene portal, se crea un vértice individual.

2. Los pasillos originales se traducen al grafo contraído: un pasillo entre
   las salas $u$ y $v$ se convierte en una arista entre sus vértices
   correspondientes (que pueden ser super-nodos si tienen portales), con peso
   1.

## Camino más corto sobre el grafo contraído

Sobre este grafo reducido se busca el camino más corto desde el vértice de
la sala 1 hasta el vértice de la sala $N$. Como la teletransportación ya
está implícita en la contracción (moverse dentro de un super-nodo cuesta 0),
el resultado es directamente la distancia mínima.

Si el vértice de la sala $N$ es inalcanzable, se devuelve $-1$.

### Dijkstra

Una primera opción es usar Dijkstra con cola de prioridad. Funciona
correctamente, pero es más maquinaria de la necesaria: todas las aristas del
grafo contraído tienen peso 1, así que la cola de prioridad no aporta nada
que una cola FIFO no pueda hacer.

- **Tiempo:** $O((N + M) \log N)$
- **Espacio:** $O(N + M)$

### BFS (simplificación)

Al tener todas las aristas peso uniforme, un BFS estándar encuentra el
camino más corto con la misma corrección que Dijkstra. La cola FIFO
garantiza que los nodos se procesan en orden creciente de distancia, que es
exactamente la propiedad que Dijkstra consigue mediante la cola de
prioridad, pero sin el coste logarítmico de mantener el heap.

El resultado es una solución más simple y con mejor complejidad:

- **Tiempo:** $O(N + M)$
- **Espacio:** $O(N + M)$

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [C_dijkstra.cpp](src/C_dijkstra.cpp) | :x: |
| [C_bfs.cpp](src/C_bfs.cpp) | :x: |
