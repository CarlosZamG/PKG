# Strings en C

Llamamos *cadena de caracteres* o simplemente *cadena*, es decir, *string* en inglés a toda secuencia finita y ordenada de caracteres. Por ejemplo, "Hola", "Mundo" y "Hola Mundo" son cadenas de caracteres.

Algunos lenguajes de programación incluyen el tipo de dato `string` o `String` para trabajar con variables de este tipo, sin embargo C no funciona de esa manera. Las cadenas en C son arreglos de caracteres en los que el final se indica con el carácter `'\0'`, en caso de no terminar con dicho carácter, sólo será un arreglo de caracteres.

**NOTA**: Al carácter `\0` se le conoce como *Null terminator character* en inglés.

### Inicializar cadenas de caracteres



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