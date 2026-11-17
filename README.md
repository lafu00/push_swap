*Este proyecto ha sido creado como parte del currículo de 42 por lafu00, lerodrig.*

# push_swap

## Descripción

`push_swap` es un proyecto pertenece al Milestone 1 del currículo de 42 y su objetivo es ordenar una
secuencia de enteros usando dos pilas, A y B, mediante un conjunto limitado de
operaciones. El programa calcula una secuencia de movimientos para dejar los
valores de A ordenados de menor a mayor.

Antes de ordenar, los argumentos se validan y cada valor recibe un índice consecutivo 
según su posición en el orden. Los algoritmos trabajan con esos índices, lo que simplifica las
comparaciones y permite ordenar valores negativos o de magnitudes distintas.

Cada pila se implementa como una lista doblemente enlazada. Cada nodo almacena
el valor original, su índice y los punteros `next` y `prev`. Las operaciones
`push`, `swap`, `rotate` y `reverse rotate` manipulan estas listas y actualizan
sus tamaños. Se incluyen rutinas especiales para entradas pequeñas, tres
estrategias generales, selección adaptativa y un modo benchmark.

## Instrucciones

### Requisitos

- cc `-Wall -Wextra -Werror`.
- `make`.
- Una plataforma compatible con la libft incluida en Libft/

### Compilación

Desde la raíz del repositorio:

```sh
make # Compila push_swap
make bonus # Compila el checker
```

El ejecutable generado se llama `push_swap`. El `Makefile` compila también la biblioteca `libft` incluida en el repositorio.

### Ejecución

Se pueden pasar los números como argumentos separados o como una cadena:

```sh
./push_swap 4 2 3 1
./push_swap "4 2 3 1"
```

También se puede elegir explícitamente la estrategia o activar las métricas:

```text
--simple     Selecciona la estrategia simple
--medium     Selecciona la estrategia medium
--complex    Selecciona la estrategia complex
--adaptive   Selecciona la estrategia adaptativa (predeterminada)
--bench      Activa el informe de benchmark
```
Las banderas de estrategia son mutuamente excluyentes. --adaptive es la estrategia utilizada por defecto cuando no se indica otra. --bench no mezcla las métricas con la solución: las instrucciones siguen saliendo por stdout y el resumen se escribe en stderr.

Por ejemplo:

```sh
./push_swap --bench --adaptive 4 2 3 1
```

El benchmark informa del desorden, la estrategia y el recuento total y por tipo de operación en la salida de error. Sin `--bench`, el programa está pensado para emitir los movimientos por la salida estándar.

Una comprobación habitual combina ambos programas:

```sh
./push_swap 4 1 3 2 | ./checker 4 1 3 2
# OK
```

Para limpiar los archivos generados:

```sh
make clean
make fclean
```

## Algoritmos: selección y justificación

Las estrategias se aplican sobre índices normalizados, no directamente sobre
los valores. Así, Radix puede operar sobre enteros no negativos y el algoritmo
no depende de la magnitud ni del signo de los datos originales. 

La selección adaptativa mide el desorden como la proporción de pares que están fuera de orden y usa estos umbrales: <  `0.2` para Simple, <= `0.2` a <`0.5` para Medium y >=`0.5` para Complex.

- **Entradas de hasta cinco elementos:** se resuelven con rutinas específicas
  (`sort_3` y `sort_5`). En estos tamaños pequeños, los casos explícitos
  permiten controlar los movimientos sin necesidad de preparar una estrategia
  general.
- **Simple:** lleva a B los índices más pequeños, ordena los elementos
  restantes y los devuelve a A. Se incluye como una estrategia sencilla para
  entradas con poco desorden. La búsqueda repetida del mínimo recorre la pila,
  por lo que su coste de recorrido es cuadrático, `O(n²)`.
- **Medium:** divide los índices en rangos (chunks) cuyo tamaño se calcula a
  partir de la raíz cuadrada del número de elementos. Los mueve a B y luego
  busca y devuelve a A los índices en orden descendente. Esta distribución
  busca reducir recorridos y movimientos frente a la estrategia Simple en
  entradas de desorden intermedio. Aunque el benchmark etiqueta esta
  estrategia como `O(n√n)`, la implementación busca el siguiente índice en B
  mediante recorridos repetidos; por ello, el coste de búsqueda puede llegar a
  `O(n²)`. El número concreto de movimientos también depende de la entrada y
  de las rotaciones necesarias.
- **Complex (Radix binario):** recorre los bits de los índices desde el menos
  significativo. En cada pasada, mueve a B los índices cuyo bit actual es
  cero (`pb`) y rota A para los que tienen un uno (`ra`); después devuelve B a
  A (`pa`). Se repite por cada bit necesario para representar el índice máximo. El coste esperado en operaciones es `O(n log n)`.
- **Adaptive (predeterminada):** selecciona una estrategia según el desorden inicial de la entrada.

## Recursos

### Subject de `push_swap` de 42:
 Es la referencia principal para los requisitos, las operaciones permitidas y los criterios de evaluación. 

### Aprendizaje entre compañeros (Peer-to-peer):
 En 42 aprendemos unos de otros. Lo que más nos ha ayudado ha sido:

- Hablar con compañeros en el cluster de las diferentes formas que tenían de abordar el proyecto, ya que trabajamos los conceptos y las decisiones de implementación mediante explicaciones, preguntas y revisión entre pares.
- Las evaluaciones cruzadas donde también se aprenden diferentes lógicas de programación que te ayudan a avanzar. Este intercambio nos ha ayudado a contrastar el funcionamiento de las operaciones,las estructuras y los algoritmos.

### libft:
Biblioteca propia incluida en el repositorio, utilizada para funciones auxiliares.

### Uso de inteligencia artificial: 
Hemos usado la IA como apoyo para que nos explique algunos conceptos y resolver dudas sobre:

- En la definición de datos y la inicialización de pilas
  (`push_swap.h`, `init_stack.c`) consultamos sobre listas doblemente enlazadas;
  para las operaciones `pa` y `pb` (`push.c`), sobre cómo enlazar y desenlazar
  nodos al moverlos entre A y B. 
  
- En la selección y la implementación de
  algoritmos (`select_strat.c`, `algo_simple.c`, `algo_medium.c` y
  `algo_complex.c`) consultamos sobre las ideas y complejidades de Simple,
  Medium y Radix. En particular, para Radix consultamos sobre índices,
  representación binaria y operadores de bits (`>>` y `&`) empleados en cada
  pasada. 

