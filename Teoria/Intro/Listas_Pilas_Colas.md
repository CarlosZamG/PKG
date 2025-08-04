# Listas, Pilas y Colas

Una estructura de datos es una forma de almacenar y organizar datos para facilitar el realizar ciertas operaciones como acceso y modificación de los mismos.

La diferencia entre una estructura de datos y un tipo abstracto de datos es que un TAD simplemente describe funcionalidad sin enfocarse en detalles de la implementación, mientras que una estructura de datos **sí implementa** un TAD, por lo tanto tiene que responder preguntas como *¿Cómo se almacena la información?* o *¿Qué algoritmos implementan las operaciones?*

**Nota**: Se pueden usar diferentes estructuras de datos para implementar un mismo tipo abstracto de dato.


#### TAD Lista

Operaciones que se pueden hacer:

- `append(item)`: Insertar al final.
- `pop_last()`: Eliminar el último elemento.
- `pop(index)`: Eliminar de una posición específica.
- `get(index)`: Obtener el valor de una posición específica.
- `set(index, index)`: Modificar el valor de una posición específica.

Las listas de Python implementan este TAD.


#### TAD Pila

Operaciones que se pueden hacer:

- `push(item)`: Apilar un elemento.
- `pop()`: Desapilar un elemento.
- `peek()`: Ver elemento en el tope de la pila.
- `is_empty()`: Checar si está vacía.

Este TAD manipula los elementos en un orden ***LIFO: Last In, First Out***, es decir, el último elemento es ser apilado es el primero en ser desapilado.

Aplicaciones:

- Balanceo de paréntesis.
- Calculadora polaca inversa.

#### TAD Cola

Operaciones que se pueden hacer:

- `enqueue(item)`: Encolar un elemento.
- `dequeue()`: Desencolar un elemento.
- `peek()`: Ver el primer elemento.
- `is_empty()`: Checar si está vacía.

Este TAD manipula los elementos en un orden ***LIFO: First In, First Out***, es decir, el primer elemento es ser encolado es el primero en ser desencolado.

**Nota**: Todas las operaciones anteriores de los TAD Pila y Cola pueden hacerse en tiempo $O(1)$ en el peor caso en análisis amortizado.


## Implementaciones sobre arreglos y sobre listas enlazadas

### Implementación sobre arreglos

Una forma de implementar los TAD's anteriores es usando como base un arreglo. Un arreglo es una colección de **tamaño fijo** de elementos que cumplen dos características muy importantes: 

1. Todos los elementos ocupan el **mismo espacio** en memoria.

2. Los elementos están almacenados de forma **contigua** en memoria.

Estos dos puntos permiten que se pueda **acceder** a cualquier elemento de un arreglo en **tiempo constante** mediante simples operaciones aritméticas.

EL principal inconveniente de utilizar arreglos para implementar los anteriores TAD's es que un arreglo tiene un tamaño fijo, mientras que en los TAD's anteriores podemos agregar y eliminar elementos, así que podríamos enfrentarnos a alguna de siguientes las dos problemáticas: O nos falta espacio para guardar más elementos, o nos sobra demasiado espacio sin utilizar (se está desperdiciando espacio).

Para lidiar con esto, al momento de implementar los TAD's, se debe implementar una funcionalidad interna de **redimensión**, que se encargue de aumentar o disminuir la capacidad del arreglo sobre el que se está implementando el TAD cada que sea conveniente.

Evidentemente debemos redimensionar para aumentar el espacio del arreglo cuando queramos agregar un nuevo elemento y ya hayamos ocupado todos los espacios disponibles del arreglo.

**¿Cómo es conveniente redimensionar?**

Supogamos que intentamos redimensionar aumentando la capacidad de nuestro arreglo de uno en uno, es decir, si nuestra capacidad actual es de 16 elementos que ya tenemos almacenados y queremos agregar un elemento más, pediríamos memoria para 17 elementos y debemos copiar los otros 16 elementos del arreglo anterior y agregar el nuevo elemento. Claramente el copiar todos esos elementos lleva un tiempo $O(n)$, por lo tanto agregar un elemento también sería $O(n)$ a partir del momento en el que superamos la capacidad del arreglo inicial, así que no parece una política de redimensión muy óptima.

Analicemos ahora el caso de un redimensionamiento incremental:

1. Partimos de una capacidad inicial $C$.

2. Cuando ya no tenemos espacio suficiente, incrementamos la capacidad de nuestro arreglo con $K$ nuevos espacios.

Queremos calcular la complejidad temporal $T(n)$ de agregar $n$ elementos.

Sea $L = \lfloor(n-C)/K \rfloor = O(n)$.

$$T(n)= 1 + 1 + 1 + \cdots + 1 + C \\ + 1 + \cdots + 1 + (C+K)\\  + 1 + \cdots + 1 + (C+2K) + 1 + \\  \cdots + 1 +  (C+L  \cdot K) + 1 + \cdots\\ \leq n + C \cdot(L +1) + K\cdot (1+ 2+\cdots+L)\\= n + C\cdot(L+1) + K\cdot((L+1)(L)/2) \\=n + O(n)+O(n^2) = O(n^2)$$

Entonces $T(n)/n = O(n^2)/n = O(n)$, dónde $T(n)/n$ representa la complejidad temporal promedio de agregar un elemento.  


Ahora analicemos un redimensionamiento en el que duplicamos la capacidad actual cada vez que necesitamos más espacio, supongamos que la capacidad inicial es $C$.

Queremos calcular la complejidad temporal $T(n)$ de agregar $n$ elementos.

$$T(n) = 1 + 1 + \cdots + 1 + C\\+1+ \cdots+1+2C+\\+1+ \cdots+1+4C+\cdots\\+1+ \cdots+1+(2^{\lceil \log_2(n/C) \rceil})\cdot C \\ \leq n + C\cdot(1+2+4+\cdots+2^{\lceil \log_2(n/C) \rceil})\\\leq n + C(2^{ \log_2(n/C) + 2}-1)\\=n + C(\frac{4n}{C}-1) = O(n)$$

Entonces la complejidad promedio de agregar un elemento es $T(n)/n = O(n)/n = O(1)$

**¿Cuándo debemos achicar el tamaño del arreglo**

En la parte anterior vimos que una buena estrategia para agrandar el arreglo era duplicar el tamaño, siguiendo esa idea una estrategia para achicar la capacidad del arreglo es reducir el espacio a la mitad, de tal manera que al hacerlo nos quede una capacidad igual al doble de la cantidad total de elementos, es decir, vamos a dividir la capacidad a la mitad cuando la cantidad total de elementos sea menor o igual a un cuarto de la capacidad  


### Referencias

1. [Elementary Data Structures (part 1): Stacks and Dynamic Arrays](https://youtu.be/ZlZoe37yWEc?si=Pk-REU0ctg3bVXJ5). YouTube: Algorithms Lab.

2. [2024-03-18 - Teórica - Introducción a Tipos de Datos Abstractos](https://youtu.be/cdpj6h8pSQk?si=wsKKrh1MzvkOHluA). YouTube: Algoritmos Fiuba Curso Buchwald.

3. [2024-03-21 - Teórica - Implementación sobre Arreglos y Estructuras enlazadas](https://youtu.be/57hepjLPA30?si=8RiiN4wYslrU0iFp). YouTube: Algoritmos Fiuba Curso Buchwald.

4. [Whiteboard: Analysis of Incremental Strategy for Dynamic Arrays](https://youtu.be/1GpWHME0vKs?si=cBe0owCuPt5TGsWS). YouTube: Algorithms Lab.

5. [Whiteboard: Analysis of Doubling Strategy for Dynamic Arrays](https://youtu.be/kMo3d_tK2Lc?si=witMR0JhJU44kDj3). YouTube: Algorithms Lab.
