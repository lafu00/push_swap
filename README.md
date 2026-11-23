*Este proyecto ha sido creado como parte del currículo de 42 por rehlich, lerodrig.*

# push_swap

## Descripción

`push_swap` es un proyecto que pertenece al Milestone 1 del currículo de 42 y su objetivo es ordenar una secuencia de enteros usando dos pilas, A y B, mediante un conjunto filo de 11 operaciones. El programa no ordena los números directamente sino que imprime la lista de operaciones que, ejecutadas sobre la pila A, la dejan ordenada de menor a mayor (con B vacía). La calidad del proyecto se mide por el número de operaciones generadas.

Visión general del funcionamiento:
 
1. Antes de ordenar, se leen y validan los argumentos.
2. Se calcula el **índice de desorden** de la entrada (entre 0 y 1) *antes* de
   hacer ningún movimiento.
3. Cada valor recibe un **índice** (su posición en el orden: 0 el menor,
   n-1 el mayor). Los algoritmos trabajan con estos índices, lo que permite
   ordenar números negativos o de magnitudes muy distintas sin cambiar nada.
4. Se elige una **estrategia** (forzada por una bandera o adaptativa) y se
   generan las operaciones.
5. Si se pidió `--bench`, se escribe un resumen de métricas en `stderr`.

Cada pila es una **lista doblemente enlazada**: cada nodo guarda el valor
original, su índice y los punteros `next` y `prev`. Las operaciones no copian
datos: *reenlazan* nodos existentes, por lo que `push`, `swap`, `rotate` y `reverse rotate` 
manipulan estas listas y actualizan sus tamaños.

Además, se incluyen rutinas especiales para entradas pequeñas, tres
estrategias generales, selección adaptativa y un modo benchmark.

## Instrucciones

### Requisitos

- Compilador `cc` con `-Wall -Wextra -Werror`.
- `make`.
- La `libft` incluida en el directorio `libft/` (se compila automáticamente).

### Compilación

Desde la raíz del repositorio:

```sh
make          # compila push_swap
make bonus    # compila checker (parte bonus)
make clean    # borra los .o
make fclean   # borra .o y ejecutables
make re       # recompila todo
```

### Ejecución

Los números se pueden pasar como argumentos separados o como una cadena:

```sh
./push_swap 4 2 3 1
./push_swap "4 2 3 1"
```

También se puede elegir explícitamente la estrategia o activar las métricas:

 
| Bandera       | Efecto                                                      |
|---------------|-------------------------------------------------------------|
| `--simple`    | Fuerza la estrategia simple                                 |
| `--medium`    | Fuerza la estrategia intermedia                             |
| `--complex`   | Fuerza la estrategia compleja                               |
| `--adaptive`  | Estrategia adaptativa (**por defecto** si no se indica otra)|
| `--bench`     | Escribe métricas por `stderr`                               |

Las banderas de estrategia son mutuamente excluyentes. Las operaciones salen por `stdout`y el resumen del `--bench` por `stderr`, para que ambas no se mezclen. `--adaptive` es la estrategia utilizada por defecto cuando no se indica otra.

Por ejemplo:

```sh
./push_swap --bench --adaptive 4 2 3 1
```

El benchmark informa del desorden, la estrategia y el recuento total y por tipo de operación en la salida de error. Sin `--bench`, el programa está pensado para emitir los movimientos por la salida estándar.

### Ejemplos de uso
 
```sh
# Estrategia por defecto (adaptativa)
./push_swap 4 2 3 1
 
# Forzar una estrategia
./push_swap --simple 5 4 3 2 1
 
# Verificar con el checker de 42 o con el nuestro
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG       # OK
 
# Contar operaciones con 500 números aleatorios
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
 
# Solo métricas (descartando las operaciones)
./push_swap --bench --adaptive $ARG > /dev/null
 
# Guardar las métricas en un fichero
./push_swap --bench $ARG 2> bench.txt | ./checker $ARG
```
 
Manejo de errores (siempre `Error\n` por `stderr`):
 
```sh
$ ./push_swap --adaptive 0 one 2 3
Error
$ ./push_swap --simple 3 2 3
Error
```
 
Sin argumentos no se muestra nada. Si la lista ya está ordenada tampoco se
imprime ninguna operación.

### Salida de `--bench`
 
Por `stderr` se muestra, en este orden: el índice de desorden (como porcentaje
con dos decimales), la estrategia usada con su complejidad, el total de
operaciones y el desglose por tipo (`sa sb ss pa pb`, `ra rb rr rra rrb rrr`).
La suma del desglose coincide siempre con el total.

## Algoritmos: selección y justificación

Las estrategias se aplican sobre índices normalizados (0.... n-1), no directamente sobre
los valores. Los motivos de esta decisión son: 
1. Los números negativos o muy grandes dejan de ser un problema.
2. Radix necesita enteros no negativos para examinar sus bits.
3. Comparar índices consecutivos permite saber siempre cuál es "el siguiente" que toca
colocar sin comparar valores arbitrarios.

El **índice de desorden** es una métrica previa (de `0` a `1`) que indica como de desordenada esta la lista antes de ejecutar el algoritmo. El programa revisa todas las parejas posibles de números y calcula qué porcentaje está en el orden incorrecto. 
- Vale `0` si La lista ya está ordenada.
- Vale `0.5` si la lista está desordenada de forma aleatoria.
- Vale `1` si la lista está totalmente invertida (de mayor a menor).

Este cálculo se hace internamente sobre un array antes de empezar. No gasta movimientos reales de `push_swap` (`sa`, `pb`, `ra`, etc.).

**Entradas muy pequeñas (n <= 5):** 
  Se resuelven con rutinas específicas (`sort_3` y `sort_5`). En estos tamaños pequeños, los casos explícitos permiten controlar los movimientos sin necesidad de preparar una estrategia
  general ya que el número de movimientos es mínimo.
  
**Estrategia Simple: estracción del mínimo - O(n²)** 
  Se busca el elemento con menor índice en A, se lleva a la cima con `ra` o `rra`
  (la dirección más corta), se pasa a B con `pb`, y se repite. Al final se
  devuelven todos con `pa`, quedando A ordenada de menor a mayor.
 
- **Por qué:** la clase de complejidad O(n²) es más sencilla de razonar y demostrar: cada uno de
  los n elementos cuesta hasta n/2 rotaciones. Es el caso base para comparar y funciona bien con pocos elementos o con listas casi ordenadas, donde el mínimo suele estar cerca de la cima.

**Estrategia intermedia: chunks - O(n√n)** 
  Divide los índices en rangos (chunks) cuyo tamaño se calcula a
  partir de la raíz cuadrada del número de elementos. Se recorre A y se envían a B los elementos del rango actual (los de la mitad baja del rango
  se rotan hacia el fondo de B para dejarlos ordenados a grandes rasgos). Después
  se devuelven a A buscando en B el mayor índice restante (descendente), por lo que
  que A queda ordenada. 
  
  - **Por qué:** la clase de complejidad O(n√n) busca reducir recorridos y movimientos frente a la estrategia Simple en entradas de desorden intermedio. Aunque el benchmark etiqueta esta
  estrategia como `O(n√n)`, la implementación busca el siguiente índice en B
  mediante recorridos repetidos; por ello, el coste de búsqueda puede llegar a
  `O(n²)`. El número concreto de movimientos también depende de la entrada y
  de las rotaciones necesarias.

**Estrategia compleja (Radix binario - O(n log n)):** 
  Se recorren los bits de los índices desde el menos significativo hasta el más significativo. En cada pasada, mueve a B los índices cuyo bit actual es cero (`pb`) y rota A para los que tienen un uno (`ra`); después devuelve B a A (`pa`). 
  Se repite por cada bit necesario para representar el índice máximo. El coste esperado en operaciones es `O(n log n)`.

  - **Por qué:** lo usamos para listas muy desordenadas porque ordena los elementos mirando su representación binaria bit a bit. Cada pasada consiste en separar los números según si su bit actual es `0` o `1` y volver a unirlos, lo que cuesta como mucho 2n movimientos. Al repetirlo por cada bit necesario, el coste máximo es siempre 2n. No importa como de desordenada este la lista,nunca se dispara el número de operaciones. Cada pasada mantiene el orden relativo que los números ya tenían de las rondas anteriores, requisito indispensable para que el algoritmo funcione correctamente.

  - **Por qué sobre índices y no valores:** Transformamos los valores reales en índices   simplificados antes de empezar y los índices serán 0..n-1. Esto evita que los números negativos den problemas con los bits y reducimos mucho las pasadas, es decir, pasamos de revisar siempre 32 bits a revisar solo los bits mínimos necesarios para representar el tamaño de la lista.

**Estrategia Adaptiva (por defecto):** Elige estrategia según el índice de desorden calculado al inicio:
 
| Desorden `d`      | Régimen | Estrategia | Objetivo del subject |
|-------------------|---------|------------|----------------------|
| `d < 0,2`         | bajo    | simple     | O(n²)                 |
| `0,2 ≤ d < 0,5`   | medio   | medium (chunks) | O(n√n)          |
| `d ≥ 0,5`         | alto    | complex (radix) | O(n log n)      |
 
- **0,5** es el desorden esperado de una permutación aleatoria (la mitad de los
  pares están invertidos). Por encima de ese valor la lista se comporta como
  aleatoria o peor, y solo conviene un método cuyo coste no dependa del orden
  inicial: Radix, con cota garantizada O(n log n).
- **0,2** significa que como mucho el 20 % de los pares está invertido: la lista
  conserva largos tramos ya ordenados. Ahí compensa un método que aproveche ese
  orden previo (extraer el mínimo desplaza poco cada elemento) en lugar de pagar
  el coste fijo de Radix.
- Entre ambos (0,2–0,5) hay desorden parcial: ni tan ordenada como para el
  método simple, ni tan caótica como para necesitar la garantía de Radix; los
  chunks dan buen rendimiento a mitad de camino.

## Reparto del trabajo
 
El plan de trabajo lo diseñó **rehlich**, que además marcó el orden de las
tareas y tomó las decisiones de arquitectura. Las decisiones principales, como
usar listas doblemente enlazadas y construir primero un `main` completo para
extraer después las funciones, se tomaron de forma conjunta. El desarrollo ha
sido principalmente conjunto, con revisión cruzada continua del código, y las
dos podemos explicar y defender cualquier parte.
 
### Trabajo conjunto
 
- **`main` del programa** (`main_flag_stack.c`): punto de partida del proyecto,
  desarrollado primero completo y refactorizado después en funciones.
- **Parseo y validación de argumentos:** unión de argumentos, separación en
  números, comprobación de enteros, rango de `int` y duplicados
  (`utils_parse.c`, `utils_valid.c`).
- **Gestión de banderas** (`--simple`, `--medium`, `--complex`, `--adaptive`,
  `--bench`) en `utils_parse.c`.
- **Cabecera `push_swap.h`.**
- **Documentación y justificación** de las estrategias y de los movimientos.
- **Diseño del `checker`.**
- **Pruebas y verificación:** comparación con el `checker` oficial y el propio,
  medición de operaciones con 100 y 500 números, revisión de memoria y de la
  norma.
- **Revisión cruzada** del código y corrección mutua de errores.

### Trabajo de rehlich
 
- **Planificación y coordinación** del proyecto.
- **Cálculo del índice de desorden y de los índices normalizados**
  (`utils_calc.c`).
- **Movimientos:** `swap.c`, `rotate.c` y `reverse.c`.
- **Estrategias:** selección de estrategia (`select_strat.c`), simple
  (`algo_simple.c`) y medium (`algo_medium.c`).
- **Casos de 2 a 5 elementos** (`sort_3`, `sort_5`).
- **Estrategia adaptativa:** integración de `select_strat.c` con los umbrales de
  `disorder_level`.
- **Bonus:** implementación del `checker`, adaptación del `get_next_line`,
  revisión y pruebas de los casos de error.
- **Makefile.**

### Trabajo de lerodrig

- **Estructura de datos:** definición de `t_node`/`t_stack`, construcción de la
  lista doble de A y creación y liberación de las pilas (`init_stack.c`).
- **Movimiento `push`** (`push.c`).
- **Estrategia complex (Radix)** (`algo_complex.c`).
- **Modo `--bench`:** métricas y desglose de operaciones por `stderr`
  (`bench.c`, `bench_utils.c`).
- **Umbrales de desorden compartidos** entre el benchmark y la estrategia
  adaptativa (`disorder_level`).
- **README.**

## Bonus: `checker`
 
`checker` es un programa independiente que **comprueba** si una lista de
operaciones ordena una pila. Se compila con `make bonus` y es el complemento
natural de `push_swap`: el uno genera las instrucciones y el otro las verifica.
 
### Uso
 
Recibe la pila A como argumentos (el primero queda en la cima) y lee las
instrucciones de `stdin`, una por línea, hasta el final de la entrada:
 
```sh
$ ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK                      # (Ctrl+D tras la última instrucción)
 
$ ./checker 3 2 1 0
sa
rra
pb
KO
 
$ ./checker 3 2 one 0
Error
$ ./checker "" 1
Error
```
 
Y combinado con `push_swap`:
 
```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG        # OK
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG
```

### Salidas
 
| Situación | Salida | Stream |
|-----------|--------|--------|
| A ordenada de menor a mayor **y** B vacía | `OK` | stdout |
| Cualquier otro resultado | `KO` | stdout |
| Argumento no entero, fuera del rango de `int`, duplicado o vacío (`""`) | `Error` | stderr |
| Instrucción que no existe o mal escrita (`"sa "`, `"SA"`, `"saa"`, línea vacía) | `Error` | stderr |
| Sin argumentos | nada | — |
 
Una pila que **ya está ordenada** sin instrucciones da `OK` (no se omite), igual que una sola cifra (`./checker 5`).
 
Del proyecto base se reutilizan el parseo, el cálculo de índices,
la creación de la lista y los 11 movimientos; el checker solo añade la lectura de instrucciones, su reconocimiento y la comprobación final.

## Recursos

### Subject de `push_swap` de 42:
 Es la referencia principal para los requisitos, las operaciones permitidas y los criterios de evaluación. 

### Aprendizaje entre compañeros (Peer-to-peer):
 En 42 aprendemos unos de otros. Lo que más nos ha ayudado ha sido:

- Hablar con compañeros en el cluster de las diferentes formas que tenían de abordar el proyecto, ya que trabajamos los conceptos y las decisiones de implementación mediante explicaciones, preguntas y revisión entre pares.
- Las evaluaciones cruzadas donde también se aprenden diferentes lógicas de programación que te ayudan a avanzar. Este intercambio nos ha ayudado a contrastar el funcionamiento de las operaciones,las estructuras y los algoritmos.

### libft:
Biblioteca propia incluida en el repositorio, utilizada para funciones auxiliares.

### get_next_line:
Reutilizamos el proyecto *get_next_line* para leer el contenido introducido por el usuario línea a línea. Permite al programa *checker* recibir y procesar cada instrucción de forma individual, confirmando si la pila final es correcta y si el usuario ha terminado con una secuencia válida.

### Uso de inteligencia artificial: 
Hemos usado la IA como apoyo para que nos explique algunos conceptos y resolver dudas sobre:

  - En la definición de datos y la inicialización de pilas(`push_swap.h`, `init_stack.c`) consultamos sobre listas doblemente enlazadas; para las operaciones `pa` y `pb` (`push.c`), sobre cómo enlazar y desenlazar nodos al moverlos entre A y B. 
    
  - En la selección y la implementación de algoritmos (`select_strat.c`, `algo_simple.c`, `algo_medium.c` y `algo_complex.c`) consultamos sobre las ideas y complejidades de Simple,
  Medium y Complex. En particular para Complex donde usamos Radix, consultamos sobre índices, representación binaria y operadores de bits (`>>` y `&`) empleados en cada pasada.

  - En el Benchmark (`bench.c`, `bench_utils.c`) consultamos cómo calcular y mostrar el
  porcentaje con dos decimales usando solo enteros y escritura por `fd`.

