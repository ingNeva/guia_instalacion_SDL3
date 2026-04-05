# 05 - Compilar SDL3_mixer desde Fuente

← [[04_-_Instalar_SDL3_en_Debian]] | Siguiente → [[06_-_Compilar_SDL3_net_desde_Fuente]]

---

## ¿Qué es SDL3_mixer?

SDL3_mixer es una librería de audio para SDL3. Permite reproducir música de fondo y efectos de sonido en formatos como WAV, OGG, MP3 y FLAC.

> [!warning] No disponible en apt
> SDL3_mixer **no está en los repositorios de Debian** (ni en Trixie ni en Bookworm). Debe compilarse manualmente desde el código fuente.

---

## Requisitos previos

Antes de compilar, asegúrate de tener SDL3 instalada en el sistema. Si no la tienes, instálala primero:

- Debian 13 (Trixie): [[04_-_Instalar_SDL3_en_Debian#Ruta A — Debian 13 Trixie o superior (recomendado)]]
- Debian 12 (Bookworm): [[06_-_Compilar_SDL3_desde_Fuente]] *(si tienes esta nota)*

También necesitas las siguientes herramientas:

```bash
sudo apt install git cmake ninja-build build-essential
```

---

## 1. Clonar el repositorio

```bash
git clone https://github.com/libsdl-org/SDL_mixer.git
cd SDL_mixer
```

> [!tip]
> El repositorio oficial siempre tiene la versión más reciente. No necesitas descargar un ZIP ni buscar releases manualmente.

---

## 2. Configurar con CMake

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
```

Esto configura el proyecto en modo Release (optimizado). CMake buscará automáticamente SDL3 en el sistema.

> [!warning] Error frecuente: versión de SDL3 incompatible
> Si ves un error como este:
> ```
> Could not find a configuration file for package "SDL3"
> compatible with requested version "X.X.X"
> ```
> Significa que la versión de SDL3 instalada (por ejemplo `3.2.10` de apt) es más antigua que la que SDL3_mixer requiere.
>
> **Solución:** debes compilar SDL3 desde fuente para obtener una versión más reciente. El proceso es el mismo que para SDL3_mixer:
>
> ```bash
> git clone https://github.com/libsdl-org/SDL.git
> cd SDL
> cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
> cmake --build build
> sudo cmake --install build
> sudo ldconfig
> ```
>
> Después de esto, vuelve al paso 2 de esta guía y repite el proceso para SDL3_mixer.
>
> → Si quieres más detalles sobre este proceso, consulta [09 - Compilar SDL3 desde Fuente](09_-_Compilar_SDL3_desde_Fuente).

---

## 3. Compilar

```bash
cmake --build build
```

Este paso puede tardar uno o dos minutos dependiendo de tu equipo.

---

## 4. Instalar en el sistema

```bash
sudo cmake --install build
```

Esto instala la librería en `/usr/local/lib` y los headers en `/usr/local/include`.

---

## 5. Actualizar el caché de librerías

Después de instalar, hay que decirle al sistema dónde encontrar la librería nueva:

```bash
sudo ldconfig
```

Sin este paso, los programas que intenten usar SDL3_mixer no la encontrarán en tiempo de ejecución.

---

## 6. Verificar la instalación

```bash
pkg-config --modversion sdl3-mixer
# Debería mostrar algo como: 3.x.x
```

---

## Usar SDL3_mixer en tu proyecto CMake

En tu `CMakeLists.txt`, agrega:

```cmake
find_package(SDL3_mixer REQUIRED)
target_link_libraries(tu_proyecto PRIVATE SDL3_mixer::SDL3_mixer)
```

Y en tu código C++:

```cpp
#include <SDL3_mixer/SDL_mixer.h>
```

---

#sdl3 #sdl3mixer #audio #compilar #debian #cmake
