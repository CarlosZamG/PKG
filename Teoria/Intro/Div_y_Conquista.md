# División y conquista

Es un **paradigma de diseño** de algoritmos que consiste en dividir el problema en subproblemas más pequeños y combinar sus soluciones para obtener la solución general.

De forma general, el paradigma sigue 3 pasos conceptuales:

1. Dividir la entrada en subproblemas más pequeños.

2. Resolver los subproblemas más pequeños.

3. Combinar las soluciones a los subproblemas en la solución al problema original.

Normalmente estos algoritmos se suelen implementar de forma recursiva para hacerlo de forma sencilla y natural. Sin embargo hay ejemplos sencillos que se pueden escribir de forma iterativa.

## Ejemplos

###  Búsqueda Binaria

El ejemplo clásico de búsqueda binaria consiste en un algoritmo para encontrar un elemento en un arreglo ordenado en tiempo $O(\log n)$. 

**Nota**: Existen otros problemas en los que se puede aplicar un enfoque similar, como buscar la parte entera de la raíz cuadrada de un entero.


```python
RecursiveBinSearch(array, start, end, target):
    if start > end:                     # O(1)
        return -1                       # O(1)
    else:
        middle = (start + end) // 2     # O(1)
        if array[middle] = target:      # O(1)
            return middle               # O(1)
        else (array[middle] != target) :
            if array[middle] > target:      # O(1)
                return RecursiveBinSearch(array, start, middle - 1, target)     # T(Ln/2⅃) o T(Ln/2⅃ - 1)
            else (array[middle] < target):
                return RecursiveBinSearch(array, middle+1, end, target)     # T(Ln/2⅃) o T(Ln/2⅃ - 1)
```


#### ¿Cómo podemos calcular la complejidad del algoritmo anterior?

La forma más natural para describir la cantidad de operaciones de elementales que hace un algoritmo recursivo es mediante una ecuación de recurrencia, que igualmente necesita de casos base. Para el algoritmo anterior queda de la siguiente manera:

$$
T(n) = \begin{cases}
   T(\frac{n}{2}) + O(1) &\text{si } n > 1 \\
   O(1) &\text{si } n = 1
\end{cases}
$$

Si $\frac{n}{2} > 1$, entonces $T(\frac{n}{2}) = T(\frac{n}{4}) + O(1)$,

así que $T(n) = T(\frac{n}{4})+O(1)+O(1) = T(\frac{n}{4})+2\cdot O(1)= T(\frac{n}{2^2})+2\cdot O(1)$


Si $\frac{n}{4} > 1$, entonces $T(\frac{n}{4}) = T(\frac{n}{8}) + O(1)$,

así que $T(n)= T(\frac{n}{8})+O(1)+ 2\cdot O(1)=T(\frac{n}{8})+3\cdot O(1) = T(\frac{n}{2^3})+3\cdot O(1)$

Afirmamos que para todo $k\in\mathbb{N}$:

$T(n) = T(\frac{n}{2^k}) + k\cdot O(1)$

Demostración por inducción:

Ya hicimos los casos base.

Supongamos que la afirmación es cierta para todo $m\leq k$.

$T(\frac{n}{2^{k+1}}) = T(\frac{n}{2^k}/2) = T(\frac{n}{2^k})-O(1) = T(n)-k\cdot O(1)-O(1)= T(n)-(k+1)\cdot O(1)$

Entonces

$T(n)=T(\frac{n}{2^{k+1}})+(k+1)\cdot O(1)$

Para alcanzar el caso base suponemos que $\frac{n}{2^k}=1$, entonces $n=2^k$, así que $k=\log_2 n$. Entonces $T(n)= T(1)+\log_2 n \cdot O(1)= O(1) + O(\log_2n)=O(\log n)$

### Máximo de un arreglo

Dado un arreglo de números, se puede calcular su elemento máximo dividiendo al arreglo en 2 mitades, izquierda y derecha , después calcularles el máximo a cada una de las mitades y por último elegir el mayor de entre los dos máximos.

### Algoritmo de Strassen

Utilizado para multiplicar matrices.

## Puntos más cercanos

Es un problema de geometría computacional que consiste en calcular el par de puntos más cercanos en el plano.

### Ordenamiento

Algunos algoritmos de ordenamiento como **Quicksort** o **Mergesort** siguen este paradigma.

# Referencias

1. **Algoritmos iluminados. Primera parte: Conceptos básicos**. Tim Roughgarden. Capítulo 3.

2. [2024-03-25 - Teórica - División y Conquista](https://youtu.be/hFZNCNO3Fps?si=FOvpflcTZaEIEEPC). YouTube: Algoritmos Fiuba Curso Buchwald.

3. [Analysis of Recursion 6 Binary Search, Best Case, and Worst Case Running Times](https://youtu.be/JEF3NmG5PeI?si=Z3lV1BTha1ArIMqk). 
YouTube: Professor Painter.

4. [Analyzing recursive algorithms: how to solve recurrences](https://youtu.be/YjrcREdUD9g?si=a1uIllPvjXv7iKnS). YouTube: Algorithms Lab.
