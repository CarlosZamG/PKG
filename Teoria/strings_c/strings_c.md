# Strings en C

Llamamos *cadena de caracteres* o simplemente *cadena*, es decir, *string* en inglés a toda secuencia finita y ordenada de caracteres. Por ejemplo, "Hola", "Mundo" y "Hola Mundo" son cadenas de caracteres.

Algunos lenguajes de programación incluyen el tipo de dato `string` o `String` para trabajar con variables de este tipo, sin embargo C no funciona de esa manera. Las cadenas en C son arreglos de caracteres en los que el final se indica con el carácter `'\0'`, en caso de no terminar con dicho carácter, sólo será un arreglo de caracteres.

**NOTA**: Al carácter `\0` se le conoce como *Null terminator character* en inglés.

### Inicializar cadenas de caracteres

La forma más simple de inicializar una cadena en C es usando una *string literal*. Una *string literal* es una parte del código fuente que se compone de un par de comillas dobles que rodean algunos caracteres. Un ejemplo sería una parte del código que se ve así: `"abcd"`. Ahora veamos cómo usar *strings literals* para inicializar cadenas en C:

```c
# include <stdio.h>

int main()
{
    char s1[] = "abcd";
    char *s2 = "abcd";

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    return 0;
}
```

Salida:

```
s1: abcd
s2: abcd
```

En la línea `char s1[] = "abcd";` lo que sucede es que se crea una arreglo de caracteres con espacio para guardar **5** caracteres porque se incluye el caracter `\0`.

En la línea `char *s2 = "abcd";` tenemos un puntero al primer carácter de `"abcd"` y s2 se maneja como una cadena, es decir, termina con el caracter `\0`.

En C, al pasar un arreglo a una función en realidad le pasamos un puntero al primer elemento del arreglo. Así que al momento de llamar `printf()` y pasarle como argumento `s1`, realmente no es muy diferente de pasarle `s2`.


¿Entonces la forma de inicializar `s1` y `s2` son equivalentes?

La respuesta es que no.

Veamos algunas diferencias:

```c
# include <stdio.h>

int main()
{
    char s1[] = "abcd";
    char *s2 = "abcd";

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    s1[0] = 'A';
    printf("s1: %s\n", s1);
    s2[0] = 'A';
    printf("s2: %s\n", s2);

    return 0;
}
```

Salida:

```
s1: abcd
s2: abcd
s1: Abcd
Segmentation fault (core dumped)
```

### El carácter `\0`


Muchas funciones de C como `printf()` utilizan el caracter `\0` para saber cuando termina una cadena:

```c
# include <stdio.h>

int main()
{
    char string[5] = "Abcd";
    char not_string[4] = "Abcd";

    printf("string: %s\n", string);
    printf("not_string: %s\n", not_string);

    return 0;
}
```

Salida:

```
string: Abcd
not_string: AbcdAbcd
```

Podemos observar que al momento de usar `printf()` para imprimir el valor de `not_string` tenemos un comportamiento inesperado, debido a que `not_string` **NO** es una cadena de caracteres.

### Referencias

1.  [***Are strings null terminated automatically by the compiler in C?***.](https://stackoverflow.com/questions/62335383/are-strings-null-terminated-automatically-by-the-compiler-in-c). StackOverflow. Revisado el 26 de julio de 2025.

2. [***String In Char Array VS. Pointer To String Literal | C Programming Tutorial***](https://youtu.be/Qp3WatLL_Hc?si=-TH8S2VVQ5MY3IGG). YouTube: Portfolio Courses. Revisado el 26 de julio de 2025.