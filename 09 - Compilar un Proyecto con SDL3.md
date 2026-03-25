# 09 - Compilar un Proyecto con SDL3

← [[08 - Primer Programa con SDL3]] | Siguiente → [[10 - Errores Comunes y Soluciones]]

---

## Método 1 — Compilar con GCC directamente

### Usando `pkg-config` (recomendado)

`pkg-config` obtiene automáticamente los flags correctos de SDL3:

```bash
gcc main.c -o mi_juego \
  $(pkg-config --cflags sdl3) \
  $(pkg-config --libs sdl3)
```

### Explicación de los flags

```bash
# Ver qué flags genera pkg-config
pkg-config --cflags sdl3
# -I/usr/include/SDL3

pkg-config --libs sdl3
# -lSDL3
```

### Con flags de depuración y warnings

```bash
gcc -Wall -Wextra -g -std=c17 main.c -o mi_juego \
  $(pkg-config --cflags --libs sdl3)
```

### Con optimización para release

```bash
gcc -O2 -std=c17 main.c -o mi_juego \
  $(pkg-config --cflags --libs sdl3)
```

### Con múltiples archivos fuente

```bash
gcc -Wall -g -std=c17 \
  main.c \
  juego.c \
  renderer.c \
  -o mi_juego \
  $(pkg-config --cflags --libs sdl3)
```

---

## Método 2 — Compilar con CMake (proyectos más grandes)

CMake es el sistema de build recomendado para proyectos SDL3 medianos y grandes.

### Estructura del proyecto

```
mi-proyecto/
├── CMakeLists.txt
├── src/
│   └── main.c
└── build/       ← se crea al configurar
```

### Archivo `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.16)
project(MiJuegoSDL3 VERSION 1.0 LANGUAGES C)

# Estándar C17
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Buscar SDL3 en el sistema
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

# Crear el ejecutable
add_executable(mi_juego src/main.c)

# Enlazar con SDL3
target_link_libraries(mi_juego PRIVATE SDL3::SDL3)

# Warnings de compilación
target_compile_options(mi_juego PRIVATE
  -Wall
  -Wextra
)
```

### Compilar con CMake

```bash
# Desde la raíz del proyecto
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build

# Ejecutar
./build/mi_juego
```

Para Release (optimizado):

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -- -j$(nproc)
```

---

## Método 3 — Makefile manual

Para proyectos pequeños con control total:

```makefile
# Makefile

CC      = gcc
CFLAGS  = -Wall -Wextra -g -std=c17 $(shell pkg-config --cflags sdl3)
LIBS    = $(shell pkg-config --libs sdl3)
TARGET  = mi_juego
SRCS    = main.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)
```

Usar con:

```bash
make          # compilar
make clean    # limpiar
```

---

## Referencia rápida de comandos

| Acción | Comando |
|--------|---------|
| Compilar un archivo | `gcc main.c -o app $(pkg-config --cflags --libs sdl3)` |
| Compilar con debug | `gcc -g -Wall main.c -o app $(pkg-config --cflags --libs sdl3)` |
| Configurar CMake | `cmake -S . -B build` |
| Build CMake | `cmake --build build` |
| Limpiar CMake | `rm -rf build/` |
| Ver flags de SDL3 | `pkg-config --cflags --libs sdl3` |

---

#sdl3 #gcc #cmake #makefile #compilacion #build
