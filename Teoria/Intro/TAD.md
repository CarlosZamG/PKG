# Tipo Abstracto de Dato

Un **Tipo Abstracto de Dato** es una extensión del concepto de *tipo de dato* que se enfoca en **modelar** *algo*. Los TAD están formados por dos partes: **datos** (estructuras de datos); y **operaciones** que actuan sobre esos datos. Se dice que las operaciones modelan el *comportamiento* de aquello que se busca representar.

Al momento de describir un TAD hacemos especial énfasis en la palabra **abstracto**, que significa que nos vamos a enfocar en **qué** comportamientos tiene el TAD, (es decir, qué operaciones puede hacer) sin pensar tanto en detalles de la implementación, que pueden variar dependiendo del lenguaje de programación. En lenguajes orientados a objetos, podemos usar clases y objetos para implementar nuestros TAD, mientras que en otros lenguajes como C o Go podemos usar `structs`.

Para poder especificar un TAD, usaremos una **interfaz de programación de aplicaciones**, abreviada como **API** por sus siglas en inglés: *application programming interface*. Dicha API consiste en una lista de las operaciones del TAD, con una descripción informal de las condiciones previas y las condiciones posteriores de la operación. Las condiciones previas son aquellas que se deben cumplir para poder llevar a cabo la operación, mientras que las condiciones posteriores son los resultados de ejecutar dicha operación.


Podemos adoptar dos posturas al momento de trabajar con un TAD:

1. Si simplemente somos usuarios del TAD, sólo nos interesa **qué** comportamientos tiene y cuáles son las condiciones previas y posteriores de dichos comportamientos, es decir, **qué** operaciones se pueden realizar con el TAD, **qué** se necesita para realizar la operación y **qué** efectos tiene.

2. Si somos los responsables de implementar un TAD, debemos enfocarnos en **cómo** vamos a implentar cada una de las operaciones del TAD, debemos tomar decisiones específicas que dependen del lenguaje de programación y afectarán directamente a la estructura interna de la implemetación del TAD.

**Nota**: Puede ser que adoptemos las dos posturas al mismo tiempo, es decir, mientras implementamos un TAD *X* puede ser que hagamos uso del TAD *Y*.


## Ejemplos de algo que NO es un TAD

Supongamos que al trabajar con un lenguaje orientado a objetos creamos una clase `Persona` con atributos como `nombres`, `apellido_paterno`, `apellido_materno` y `edad`. Si además implementamos los correspondientes `getters` y `setters` ¿Estaríamos implementando un TAD? La respuesta es que no califica como un TAD porque no está exhibiendo un comportamiento real, simplemente es un contenedor que almacena información.

### Referencias

1. [2024-03-21 - Teórica - Implementación sobre Arreglos y Estructuras enlazadas](https://youtu.be/57hepjLPA30?si=8RiiN4wYslrU0iFp). YouTube: Algoritmos Fiuba Curso Buchwald.

2. **Algorithms**. Robert Sedgewick y Kevin Wayne. Fourth edition. Pearson Education, Inc.