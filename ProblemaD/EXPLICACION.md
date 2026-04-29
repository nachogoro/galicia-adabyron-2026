# Introducción a la solución

El problema pide redistribuir aceite entre almazaras dispuestas en línea de
modo que se **maximice la cantidad mínima** de aceite en cualquier almazara.
El transporte entre almazaras vecinas tiene un coste: al mover $k$ litros
entre la almazara $i$ y la $i + 1$, solo llegan $k - c_i$.

La respuesta se puede buscar con **búsqueda binaria sobre el valor objetivo**.

## Reformulación como problema de decisión

En lugar de buscar directamente el óptimo, respondemos a una pregunta
auxiliar:

> Dado un valor $T$, ¿es posible redistribuir el aceite de modo que toda
> almazara tenga al menos $T$ litros?

Este predicado es **monótono**: si $T$ es alcanzable, cualquier $T' < T$
también lo es (basta redistribuir menos). Esto permite aplicar búsqueda
binaria sobre $T$.

## Búsqueda binaria

Los extremos del intervalo de búsqueda son:

- **Cota inferior:** el mínimo de los $x_i$. Con $T$ menor o igual al
  mínimo, no hace falta mover nada.
- **Cota superior:** el máximo de los $x_i$ (nunca se puede superar la
  almazara más llena sin aportación externa).

Para cada candidato $T$, se comprueba si es factible. El mayor $T$ factible es
la respuesta.

## Verificación greedy

Para un $T$ dado, cada almazara $i$ tiene un sobrante local $x_i - T$:
positivo si puede donar aceite, negativo si necesita recibirlo.

La verificación recorre las almazaras de izquierda a derecha manteniendo un
**balance acumulado**. Este balance representa cuánto aceite neto puede
ofrecer el subarray izquierdo $[1..i]$ al subarray derecho $[i+1..n]$, una
vez que todas las almazaras a la izquierda ya tienen al menos $T$ litros.
Cuando el balance es negativo, significa que la parte izquierda tiene un
déficit que las almazaras de la derecha deberán cubrir.

Al pasar de una almazara a la siguiente, el balance cruza la arista
$(i, i+1)$ con coste $c_i$. Se distinguen tres casos:

1. **Exceso grande** ($balance > c_i > 0$): hay suficiente aceite sobrante
   para pagar el transporte. A la siguiente almazara llegan
   $balance - c_i$ litros.

2. **Exceso pequeño** ($0 \leq balance \leq c_i$): el sobrante no cubre el
   coste de transporte. Ese aceite sobrante queda varado y se pierde: el
   balance se resetea a 0.

3. **Déficit** ($balance < 0$): la parte izquierda necesita aceite. El
   déficit se propaga y **crece** en $c_i$, porque quien lo cubra desde la
   derecha también pagará el coste de transportar el aceite de vuelta a
   través de esa arista.

En cada almazara $i$ se suma su sobrante local $x_i - T$ al balance.

Un solo barrido de izquierda a derecha es suficiente aunque el aceite en la
práctica pueda fluir en ambas direcciones, porque no estamos decidiendo
flujos concretos: estamos comprobando si el sistema es globalmente
solvente. El balance final indica si la suma de todos los excesos y
déficits, descontando las pérdidas de transporte acumuladas, es no negativa.
Si lo es, existe una redistribución válida; si no, ninguna redistribución
puede alcanzar el objetivo $T$.

## Complejidad

- **Tiempo:** $O(N \log(\max(x_i)))$: $O(N)$ por cada verificación,
  $O(\log(\max(x_i)))$ iteraciones de búsqueda binaria.
- **Espacio:** $O(N)$

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [D.cpp](src/D.cpp) | :x: |
