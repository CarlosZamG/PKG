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

Este TAD manipula los elementos en un orden *LIFO: Last In, First Out*, es decir, el último elemento es ser apilado es el primero en ser desapilado.

Aplicaciones:

- Balanceo de paréntesis.
- Calculadora polaca inversa.

#### TAD Cola

Operaciones que se pueden hacer:

- `enqueue(item)`: Encolar un elemento.
- `dequeue()`: Desencolar un elemento.
- `peek()`: Ver el primer elemento.
- `is_empty()`: Checar si está vacía.

Este TAD manipula los elementos en un orden *LIFO: First In, First Out*, es decir, el primer elemento es ser encolado es el primero en ser desencolado.

**Nota**: Todas las operaciones anteriores de los TAD Pila y Cola pueden hacerse en tiempo $O(1)$ en el peor caso en análisis amortizado.




### Referencias

1. [Elementary Data Structures (part 1): Stacks and Dynamic Arrays](https://youtu.be/ZlZoe37yWEc?si=Pk-REU0ctg3bVXJ5). YouTube: Algorithms Lab.

2. [2024-03-18 - Teórica - Introducción a Tipos de Datos Abstractos](https://youtu.be/cdpj6h8pSQk?si=wsKKrh1MzvkOHluA). YouTube: Algoritmos Fiuba Curso Buchwald