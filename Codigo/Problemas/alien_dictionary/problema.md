# 953 Verifying an Alien Dictionary

En un idioma alienígena, sorprendentemente, también usan letras minúsculas en inglés, pero posiblemente en un orden diferente. El orden del alfabeto es una permutación de las letras minúsculas.

Dada una secuencia de palabras escritas en el idioma alienígena y el orden del alfabeto, devuelve `true` si y solo si las palabras dadas están ordenadas lexicográficamente en este idioma alienígena.

___
- **Ejemplo 1:**

Input: 

`words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"`

Output: 

`true`
___
- **Ejemplo 2:**

Input: 

`words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"`

Output: 

`false`
___
- **Ejemplo 3:**

Input: 

`words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"`


Output: 

`false`