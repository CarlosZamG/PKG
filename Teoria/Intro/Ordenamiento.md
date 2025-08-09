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

### Mergesort

```mermaid
graph TD
  %% Top
  A["[8, 5, 2, 1, 17, 4, 10, 6]"]:::lightpurple

  %% Split level
  A --> L["[8, 5, 2, 1]"]:::lightpurple
  A --> R["[17, 4, 10, 6]"]:::lightpurple

  %% Left subtree
  L --> L1["[8, 5]"]:::lightpurple
  L --> L2["[2, 1]"]:::lightpurple

  L1 --> l11["[8]"]:::mint
  L1 --> l12["[5]"]:::mint
  L2 --> l21["[2]"]:::mint
  L2 --> l22["[1]"]:::mint

  %% Left merges
  l11 --> mL1["[5, 8]"]:::mint
  l12 --> mL1
  l21 --> mL2["[1, 2]"]:::mint
  l22 --> mL2

  mL1 --> leftSorted["[1, 2, 5, 8]"]:::mint
  mL2 --> leftSorted

  %% Right subtree
  R --> R1["[17, 4]"]:::lightpurple
  R --> R2["[10, 6]"]:::lightpurple

  R1 --> r11["[17]"]:::mint
  R1 --> r12["[4]"]:::mint
  R2 --> r21["[10]"]:::mint
  R2 --> r22["[6]"]:::mint

  %% Right merges
  r11 --> mR1["[4, 17]"]:::mint
  r12 --> mR1
  r21 --> mR2["[6, 10]"]:::mint
  r22 --> mR2

  mR1 --> rightSorted["[4, 6, 10, 17]"]:::mint
  mR2 --> rightSorted

  %% Final merge
  leftSorted --> FINAL["[1, 2, 4, 5, 6, 8, 10 17]"]:::mint
  rightSorted --> FINAL

  %% Classes (colors)
  classDef purple fill:#a68be8,stroke:#6a3fa8,stroke-width:1px;
  classDef lightpurple fill:#d9c9f8,stroke:#6a3fa8,stroke-width:1px;
  classDef mint fill:#9fe6B3,stroke:#2f7a3a,stroke-width:1px;
```


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