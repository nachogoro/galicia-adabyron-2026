# Problema F - Ruta del Marisco

En la costa de Galicia, las cofradías de pescadores necesitan optimizar el transporte de marisco fresco
desde distintos puertos costeros hasta una lonja central donde será subastado.

Los diferentes puertos están conectados por carreteras y rutas marítimas, cada una con una longitud
distinta (en kilómetros). El marisco debe ser transportado desde todos los puertos hasta una lonja
principal que se ubicará en uno de ellos. Se asume que los transportistas, aunque pasen por otros
puertos, no hacen paradas ni cargan en los mismos.

El coste de transporte es proporcional a la distancia recorrida. Para garantizar que ningún puerto
tenga un coste excesivo, las cofradías quieren elegir la ubicación de la lonja de manera que se minimice
la distancia máxima desde cualquier puerto hasta ella.

Sin embargo, existe una dificultad: las rutas atraviesan zonas complicadas como rías, acantilados y
carreteras sinuosas, por lo que la distancia real entre dos puertos no es simplemente el número de
conexiones, sino la suma de las longitudes de cada tramo.

Dado el conjunto de puertos y las distancias reales entre ellos, se debe evaluar cada puerto **candidato**
como posible ubicación de la lonja, teniendo en cuenta que no todos los puertos del conjunto son
necesariamente aptos para ello. Para cada candidato, se calculará la mayor distancia que tendría que
recorrerse desde cualquier otro puerto hasta él. Finalmente, se elegirá como ubicación óptima aquel
puerto cuya distancia máxima al resto sea la menor posible.

## Entrada

La primera línea contiene dos enteros: N (número de puertos, $1 < N \leq 10000$) y M (número de
conexiones, $1 \leq M \leq \min\left(\frac{N(N-1)}{2},\ 250000\right)$).

Las siguientes M líneas contienen tres enteros (a, b, dist) que indican una conexión bidireccional entre
el puerto a y el puerto b con una longitud dist ($1 \leq dist \leq 1000$).

La siguiente línea contiene un entero K ($1 \leq K \leq \min(N, 2500)$) con el número de puertos candidatos.

La última línea contiene K enteros distintos que representan los IDs de los puertos candidatos.

Se garantiza que el grafo es conexo y que $K \times (N + M) \leq 2 \cdot 10^8$.

## Salida

Un único entero que representa la mínima distancia máxima desde cualquier puerto candidato a todos
los demás puertos. Es decir, para cada puerto candidato se considera la distancia más larga hasta
cualquier otro puerto (siguiendo las rutas disponibles). Entre todos los candidatos, se debe elegir aquel
cuyo valor máximo sea el menor posible, y devolver dicho valor.

## Entrada de ejemplo
```
4 5
1 2 5
1 3 10
2 3 3
2 4 8
3 4 2
2
2 3
```

## Salida de ejemplo
```
5
```
