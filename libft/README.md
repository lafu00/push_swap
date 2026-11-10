*Este proyecto ha sido creado como parte del currículo de 42 por lerodrig.*

# Libft - Mi Primera Librería

## Descripción

**Libft** es el primer proyecto individual del Cursus de 42. Consiste en crear una librería en C (`libft.a`) que reescribe varias funciones de la `libc` y añade otras de utilidad para cadenas, memoria y listas enlazadas.

El objetivo es entender cómo funcionan estas funciones por dentro, practicar la gestión de memoria con `malloc` y `free`, dominar los punteros y tener una herramienta propia para proyectos futuros.

---

## Instrucciones

### Requisitos y Reglas 
- **Lenguaje:** C (según la Norma de 42).
- **Flags de compilación:** `-Wall -Werror -Wextra`.
- **Generación de la librería:** Debe utilizarse la herramienta `ar`.
- **Variables globales:** No pueden usarse.
- **Funciones auxiliares:** Si se descomponen funciones complejas, las funciones auxiliares se maracarán como `static`.
- **Gestión de memoria:** Se deben evitar los *leaks* de memoria y comportamientos indefinidos (`segfault`, `double free`, `bus error`).

### Compilación

El proyecto incluye un `Makefile` con las reglas estándar requeridas:

| Regla | Descripción |
|---|---|
| `make` / `make all` | Compila los archivos fuente obligatorios y genera la librería `libft.a` en la raíz del repositorio. |
| `make clean` | Elimina todos los archivos objeto (`.o`). |
| `make fclean` | Elimina los archivos objeto (`.o`) y la librería generada (`libft.a`). |
| `make re` | Ejecuta `fclean` y vuelve a compilar el proyecto desde cero. |

### Uso en Otros Proyectos

Para integrar **Libft** en tus propios programas en C:

1. Añade el header en tu código:
   ```c
   #include "libft.h"
   ```
2. Compila enlazando la librería:
   ```bash
   cc -Wall -Werror -Wextra main.c -L. -lft -o mi_programa
   ```

---

## Estructura de la Librería

### Parte 1: Funciones Reescritas de libc

Estas funciones recrean el comportamiento de las de la `libc`, utilizando el prefijo `ft_`.

#### Clasificación y Conversión de Caracteres

- **`int ft_isalpha(int c)`:** Comprueba si `c` es un carácter alfabético (A-Z o a-z).

- **`int ft_isdigit(int c)`:** Comprueba si `c` es un dígito numérico ('0' a '9').

- **`int ft_isalnum(int c)`:** Comprueba si `c` es un carácter alfanumérico (letra o dígito).

- **`int ft_isascii(int c)`:** Comprueba si `c` pertenece al grupo de caracteres ASCII (valores de 0 a 127).
 
- **`int ft_isprint(int c)`:** Comprueba si `c` es un carácter imprimible (ASCII 32 a 126, incluyendo el espacio).

- **`int ft_toupper(int c)`:** Convierte un carácter de minúscula a mayúscula.

- **`int ft_tolower(int c)`:** Convierte un carácter de mayúscula a minúscula.


#### Manipulación de Memoria

- **`void *ft_memset(void *b, int c, size_t len)`:** Rellena los primeros `len` bytes del área de memoria apuntada por `b` con el valor `c` (convertido a `unsigned char`).

- **`void ft_bzero(void *s, size_t n)`:** Escribe bytes cero (`\0`) en los primeros `n` bytes del área de memoria `s`.

- **`void *ft_memcpy(void *dst, const void *src, size_t n)`:** Copia `n` bytes desde el área de memoria `src` hacia `dst`. Las áreas no deben solaparse.

- **`void *ft_memmove(void *dst, const void *src, size_t len)`:** Copia `len` bytes de `src` a `dst`. A diferencia de `memcpy`, maneja de forma segura las zonas de memoria que se solapan (utilizando un buffer intermedio o copiando en sentido inverso si `dst > src`).

- **`void *ft_memchr(const void *s, int c, size_t n)`:** Busca la primera ocurrencia del byte `c` (convertido a `unsigned char`) en los primeros `n` bytes de la memoria `s`.

- **`int ft_memcmp(const void *s1, const void *s2, size_t n)`:** Compara byte a byte los primeros `n` bytes de los bloques de memoria `s1` y `s2`.


#### Manipulación de Cadenas y Conversiones

- **`size_t ft_strlen(const char *s)`:** Calcula la longitud de la cadena `s` sin contar el carácter nulo final (`\0`).

- **`size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)`:** Copia hasta `dstsize - 1` caracteres de `src` a `dst`, garantizando la terminación nula si `dstsize > 0`.

- **`size_t ft_strlcat(char *dst, const char *src, size_t dstsize)`:** Concatena `src` al final de `dst`, asegurando no superar `dstsize` bytes totales y garantizando la terminación nula.

- **`char *ft_strchr(const char *s, int c)`:** Busca la primera ocurrencia del carácter `c` en la cadena `s`.

- **`char *ft_strrchr(const char *s, int c)`:** Busca la última ocurrencia del carácter `c` en la cadena `s`.

- **`int ft_strncmp(const char *s1, const char *s2, size_t n)`:** Compara como máximo `n` caracteres de las cadenas `s1` y `s2`.

- **`char *ft_strnstr(const char *haystack, const char *needle, size_t len)`:** Busca la primera ocurrencia de la subcadena `needle` dentro de `haystack`, limitando la búsqueda a los primeros `len` caracteres.

- **`int ft_atoi(const char *str)`:** Convierte el tramo inicial de una cadena de texto en un número entero (`int`), omitiendo espacios en blanco e identificando signos `+` / `-`.


#### Gestión Dinámica de Memoria

- **`void *ft_calloc(size_t count, size_t size)`:** Reserva memoria dinámicamente para un array de `count` elementos de `size` bytes cada uno, e inicializa todos los bytes a cero. Si `count` o `size` es 0, devuelve un puntero único que puede ser liberado limpiamente con `free()`.

- **`char *ft_strdup(const char *s1)`:** Crea una copia idéntica de la cadena `s1` en una nueva región de memoria reservada con `malloc`.


---

### Parte 2: Funciones Adicionales

Funciones que no están presentes en la biblioteca estándar de C o que tienen especificaciones concretas.

- **`char *ft_substr(char const *s, unsigned int start, size_t len)`:** Extrae una subcadena de `s` comenzando en el índice `start` y con una longitud máxima de `len` bytes, utilizando `malloc`.

- **`char *ft_strjoin(char const *s1, char const *s2)`:** Crea una nueva cadena resultante de la concatenación de `s1` y `s2`.


- **`char *ft_strtrim(char const *s1, char const *set)`:** Elimina todos los caracteres pertenecientes al conjunto `set` tanto del inicio como del final de la cadena `s1`.

- **`char **ft_split(char const *s, char c)`:** Divide la cadena `s` en un array de subcadenas delimitadas por el carácter `c`. El array resultante finaliza obligatoriamente con un puntero `NULL`.

- **`char *ft_itoa(int n)`:** Convierte un número entero `n` en su representación textual (cadena de caracteres). Maneja correctamente números negativos y el límite mínimo de enteros (`INT_MIN`).

- **`char *ft_strmapi(char const *s, char (*f)(unsigned int, char))`:** Genera una nueva cadena aplicando la función `f` a cada carácter de `s`, pasando el índice del carácter como primer parámetro.

- **`void ft_striteri(char *s, void (*f)(unsigned int, char*))`:** Itera sobre la cadena `s` y aplica la función `f` a cada carácter, pasando su índice y la dirección de memoria del propio carácter para poder modificarlo in-place.

- **`void ft_putchar_fd(char c, int fd)`:** Escribe el carácter `c` en el descriptor de archivo `fd` dado (ej. `1` para salida estándar, `2` para salida de error).

- **`void ft_putstr_fd(char *s, int fd)`:** Escribe la cadena `s` en el descriptor de archivo `fd`.

- **`void ft_putendl_fd(char *s, int fd)`:** Escribe la cadena `s` seguida de un salto de línea (`\n`) en el descriptor de archivo `fd`.

- **`void ft_putnbr_fd(int n, int fd)`:** Escribe la representación textual del entero `n` en el descriptor de archivo `fd`.


---

### Parte 3: Listas Enlazadas

Estructura definida en `libft.h`:

```c
typedef struct s_list
{
    void          *content;
    struct s_list *next;
} t_list;
```

- **`t_list *ft_lstnew(void *content)`:** Crea un nuevo nodo de lista asignando memoria con `malloc`. Inicializa `content` con el parámetro recibido y `next` a `NULL`.

- **`void ft_lstadd_front(t_list **lst, t_list *new)`:** Inserta el nodo `new` al principio de la lista `lst`.

- **`int ft_lstsize(t_list *lst)`:** Cuenta el número de nodos presentes en la lista.

- **`t_list *ft_lstlast(t_list *lst)`:** Recorre la lista y devuelve un puntero al último nodo.

- **`void ft_lstadd_back(t_list **lst, t_list *new)`:** Inserta el nodo `new` al final de la lista `lst`.

- **`void ft_lstdelone(t_list *lst, void (*del)(void *))`:** Libera la memoria del contenido del nodo `lst` aplicando la función `del`, y después libera la memoria del propio nodo mediante `free`. No altera el siguiente nodo (`next`).

- **`void ft_lstclear(t_list **lst, void (*del)(void *))`:** Elimina y libera iterativamente el nodo dado y todos sus sucesores en la lista utilizando `del` y `free`. Al finalizar, establece el puntero de la lista a `NULL`.

- **`void ft_lstiter(t_list *lst, void (*f)(void *))`:** Recorre la lista `lst` y ejecuta la función `f` sobre el contenido de cada elemento.

- **`t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`:** Itera la lista `lst`, aplica la función `f` al contenido de cada nodo y crea una nueva lista con los resultados obtenidos. Si falla una reserva de memoria en mitad del proceso, utiliza `del` y `free` para eliminar limpia y completamente los nodos recién creados y evita fugas de memoria.


---

## Recursos

### Documentación y Referencias
- Manuales de C de UNIX / Linux (man): Es el recurso  más importante. Ejecutar comandos como man strlen, man memcpy o man malloc en la terminal permite conocer el comportamiento exacto, los parámetros y los valores de retorno que se deben replicar en cada función.

### Aprendizaje Peer-to-Peer 
En 42 aprendemos unos de otros. Lo que más me ha ayudado ha sido:

- Hablar con compañeros en el cluster de las diferentes formas que tenían de abordar los ejercicios.
- Las evaluaciones cruzadas donde también se aprenden diferentes lógicas de programación que te ayudan a avanzar.

### Uso de Inteligencia Artificial
En este proyecto he usado la IA como apoyo para aprender y resolver dudas:

- **Entender los punteros, punteros dobles y punteros a función**.
- **Entender el casting a `unsigned char` y alineación de memoria**.
- **Entender las listas enlazadas**: cómo se conectan los nodos entre sí y para qué sirve cada parte de la estructura.

No usé la IA para que me diera el código final ni para saltarme la lógica. Escribí, probé y razoné todo el código yo misma, porque necesito poder explicarlo y reproducirlo en las evaluaciones y los exámenes.
