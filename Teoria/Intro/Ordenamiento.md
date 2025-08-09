# Ordenamiento

Existen 2 tipos de ordenamiento: Ordenamientos comparativos y no comparativos.

Los ordenamientos comparativos se basan en comparar dos elementos entre sí. Algunos ejemplos de ordenamientos comparativos son Bubblesort, Selección, Inserción, Mergesort, Quicksort.

**¿Cuánto es lo mínimo que le toma a un algoritmo de ordenamiento comparativo ordenar?**

A continuación se muestra el árbol de comparaciones de 3 elementos:

```mermaid
graph TD

    root["[A, B, C]<br/>A < B"]

    root -->|SI| b_lt_c["B < C"]
    root -->|NO| b_lt_c2["B < C"]

    %% Left branch
    b_lt_c -->|SI| abc["[A, B, C]"]
    b_lt_c -->|NO| a_lt_c["A < C"]

    a_lt_c -->|SI| acb["[A, C, B]"]
    a_lt_c -->|NO| cab["[C, A, B]"]

    %% Right branch
    b_lt_c2 -->|SI| a_lt_c2["A < C"]
    b_lt_c2 -->|NO| cba["[C, B, A]"]

    a_lt_c2 -->|SI| bac["[B, A, C]"]
    a_lt_c2 -->|NO| bca["[B, C, A]"]

```

La cantidad de comparaciones se relaciona con la altura de dicho árbol. Para un arreglo de $n$ elementos, el árbol tendrá $n!$ hojas. Si $C$ es la cantidad de nodos, entonces la altura del árbol es $h=\lfloor\log_2 (C) \rfloor$. En el último nivel de un árbol binario tenemos a lo más $2^h$. Entonces $2^h \geq n!$, así que $h\geq\log_2(n!)$, entonces $h = \Omega(\log(n!))=\Omega(n \log n)$

___
**Proposición**:

$$\Omega(n\log n) = \Omega(\log(n!))$$

Demostración:

$$\log(n!) = \log(1\cdot2\cdot3\cdots n)=\\\log(1)+\log(2)+\cdots+\log(\frac{n}{2})+\log(\frac{n}{2}+1)+\cdots+\log(n)>\\ \log(\frac{n}{2}+1)+\cdots+\log(n)>\\\log( n/2)+\cdots+\log(n/2) = \frac{n}{2}\log(n/2)=\frac{n}{2}\cdot(\log(n)-log(2))=\Omega(n\log n)$$

___


Por lo tanto no puede existir un algoritmo de ordenamiento comparativo que sea mejor que $O(n\log n)$


### Quicksort

```mermaid
graph TD
    %% Root
    A["[8, 4, 3, 1, 6, 7, 11, 9, 2, 10,  <span style='color:red'>5</span>]"]:::yellow

    %% Level 1
    A --> B["[4, 3, 1, <span style='color:red'>2<span>]"]:::yellow
    A --> C["[5]"]:::green
    A --> D["[8,  6,  7,  11,  9,  <span style='color:red'>10<span>]"]:::yellow

    %% Left partition
    B --> E["[1]"]:::green
    B --> F["[2]"]:::green
    B --> G["[4, <span style='color:red'>3<span>]"]:::yellow

    G --> H["[ ]"]
    G --> I["[3]"]:::green
    G --> J["[4]"]:::green

    %% Right partition
    D --> K["[8, 6, 7, <span style='color:red'>9<span>]"]:::yellow
    D --> L["[10]"]:::green
    D --> M["[11]"]:::green

    K --> N["[8  6  <span style='color:red'>7<span>]"]:::yellow
    K --> O["[9]"]:::green
    K --> P["[ ]"]

    N --> Q["[6]"]:::green
    N --> R["[7]"]:::green
    N --> S["[8]"]:::green

    %% Styles
    classDef green fill:#a3d9a5,stroke:#333,stroke-width:1px;
    classDef yellow fill:#fff2b2,stroke:#333,stroke-width:1px;
    
```

# Referencias

[2024-04-08 - Teórica - Ordenamientos no Comparativos - Counting Sort](https://youtu.be/v0DGQ8tYcis?si=3bIl_SPF5pI-mXPb). YouTube: Algoritmos Fiuba Curso Buchwald