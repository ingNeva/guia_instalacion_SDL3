# 06 - Compilar SDL3_net desde Fuente

← [05_-_Compilar_SDL3_mixer_desde_Fuente](05_-_Compilar_SDL3_mixer_desde_Fuente) | Siguiente → [07 - Dependencias de SDL3](07_-_Dependencias_de_SDL3)

---

## ¿Qué es SDL3_net?

SDL3_net es una librería de red para SDL3. Permite crear conexiones TCP y UDP, útil para juegos multijugador o cualquier funcionalidad que requiera comunicación por red.

> [!warning] No disponible en apt
> SDL3_net **no está en los repositorios de Debian** (ni en Trixie ni en Bookworm). Debe compilarse manualmente desde el código fuente.

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
git clone https://github.com/libsdl-org/SDL_net.git
cd SDL_net
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
> Significa que la versión de SDL3 instalada es más antigua que la que SDL3_net requiere. Solución: actualiza SDL3 primero o compílala también desde fuente.

---

## 3. Compilar

```bash
cmake --build build
```

Este paso es rápido, SDL3_net es una librería pequeña.

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

Sin este paso, los programas que intenten usar SDL3_net no la encontrarán en tiempo de ejecución.

---

## 6. Verificar la instalación

```bash
pkg-config --modversion SDL3_net
# Debería mostrar algo como: 3.x.x
```

---

## Usar SDL3_net en tu proyecto CMake

En tu `CMakeLists.txt`, agrega:

```cmake
find_package(SDL3_net REQUIRED)
target_link_libraries(tu_proyecto PRIVATE SDL3_net::SDL3_net)
```

Y en tu código C++:

```cpp
#include <SDL3_net/SDL_net.h>
```

---

#sdl3 #sdl3net #red #networking #compilar #debian #cmake
