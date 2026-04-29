# Problema B - Palabra Dominante

En muchos textos, algunas palabras aparecen más veces que otras. En análisis de lenguaje, a veces
interesa saber si existe una palabra que destaque claramente sobre las demás.

Dada una línea de texto formada por palabras separadas por un espacio, diremos que una palabra es
**dominante** si aparece estrictamente más veces que cualquier otra palabra del texto.

Tu tarea consiste en determinar si existe una palabra dominante en el texto dado.

Si existe exactamente una palabra que aparece más veces que todas las demás, deberás imprimir dicha
palabra. En caso contrario, si dos o más palabras comparten la frecuencia máxima, se considera que
hay un empate y deberás imprimir como resultado la palabra "empate".

## Entrada

La entrada contiene una sola línea con una cadena de $S$ palabras ($1 \leq S \leq 10^5$). Las palabras están
separadas exactamente por un único espacio y tendrán un tamaño máximo de 30 caracteres.

## Salida

- Si existe una palabra dominante, imprime esa palabra.
- Si hay empate entre dos o más palabras con la frecuencia máxima, imprime: empate

## Entrada de ejemplo 1
```
hola mundo hola hola test mundo
```

## Salida de ejemplo 1
```
hola
```

## Entrada de ejemplo 2
```
rojo azul rojo verde azul
```

## Salida de ejemplo 2
```
empate
```
