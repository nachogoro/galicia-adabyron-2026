# Introducción a la solución

El problema pide elegir, entre un subconjunto de $K$ puertos candidatos, aquel
cuya distancia máxima a cualquier otro puerto sea la menor posible. Las
conexiones entre puertos tienen pesos distintos, así que se trata de caminos
más cortos en un grafo ponderado.

## Dijkstra desde cada candidato

Para cada puerto candidato se ejecuta Dijkstra, obteniendo las distancias
más cortas a todos los demás puertos. De ese vector de distancias se toma el
máximo (la distancia al puerto más lejano). La respuesta es el mínimo de
esos máximos entre todos los candidatos.

## Complejidad

- **Tiempo:** $O(K \cdot (N + M) \log N)$. Cada Dijkstra con cola de
  prioridad cuesta $O((N + M) \log N)$ y se ejecuta $K$ veces.
- **Espacio:** $O(N + M)$

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------: | :--------------------: |
| [F.cpp](src/F.cpp) | Dijkstra desde cada candidato | :x: |
