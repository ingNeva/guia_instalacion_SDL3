# 08 - Compilar SDL3 desde Fuente

← [07_-_Dependencias_de_SDL3](07_-_Dependencias_de_SDL3) | Siguiente → [09_-_Configurar_el_Linker_para_SDL3](09_-_Configurar_el_Linker_para_SDL3)

---

## Antes de empezar — Desinstalar la versión anterior

Si tienes SDL3 instalada desde `apt`, desinstálala primero para evitar conflictos con la versión que vas a compilar:

```bash
sudo apt remove --purge libsdl3-dev libsdl3-3
sudo apt autoremove
```

Verifica que no quede ningún rastro:

```bash
pkg-config --modversion sdl3
# Debe devolver un error — si muestra una versión, revisa que no queden archivos huérfanos
```

---

## Cuándo usar este método

- Estás en **Debian 12 Bookworm** (sin `libsdl3-dev` en apt)
- Necesitas una versión específica de SDL3
- Quieres la versión más reciente disponible

---

## Paso 1 — Instalar dependencias

Antes de todo, instala las dependencias de compilación:

```bash
sudo apt-get install -y \
  build-essential git make pkg-config cmake ninja-build \
  libasound2-dev libpulse-dev libaudio-dev libjack-dev \
  libsndio-dev libx11-dev libxext-dev libxrandr-dev \
  libxcursor-dev libxfixes-dev libxi-dev libxss-dev \
  libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev \
  libgles2-mesa-dev libegl1-mesa-dev libdbus-1-dev \
  libibus-1.0-dev libudev-dev
```

Ver lista completa en [[07_-_Dependencias_de_SDL3]].

---

## Paso 2 — Descargar el código fuente de SDL3

```bash
git clone https://github.com/libsdl-org/SDL.git SDL3-src
cd SDL3-src
```

> [!tip]
> Esto siempre descarga la última versión disponible del repositorio oficial.

---

## Paso 3 — Configurar con CMake

```bash
cmake -S . -B build
```

Para una compilación optimizada de Release:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
```

Con tests y documentación (opcional):

```bash
cmake -S . -B build \
  -DCMAKE_BUILD_TYPE=Release \
  -DSDL_INSTALL_DOCS=TRUE \
  -DSDL_TESTS=ON
```

---

## Paso 4 — Compilar

```bash
cmake --build build
```

> [!tip] Acelerar la compilación
> Usa `-j` con el número de núcleos de tu CPU para compilar en paralelo:
> ```bash
> cmake --build build -- -j$(nproc)
> ```
> `nproc` devuelve automáticamente el número de núcleos disponibles.

---

## Paso 5 — Instalar

### Opción A: Instalar en `/usr` (recomendado para Debian)

Instala donde Debian espera encontrar las librerías del sistema:

```bash
sudo cmake --install build --prefix /usr
```

Esto coloca los archivos en:
- `/usr/lib/` — las librerías `.so`
- `/usr/include/SDL3/` — los headers
- `/usr/lib/pkgconfig/` — los archivos `.pc` para `pkg-config`

### Opción B: Instalar en `/usr/local` (predeterminado de CMake)

```bash
sudo cmake --install build --prefix /usr/local
```

> [!warning] Si usas `/usr/local`
> Necesitarás configurar el linker para que encuentre SDL3. Ver [[09_-_Configurar_el_Linker_para_SDL3]].

---

## Paso 6 — Verificar la instalación

```bash
# Verificar que el archivo .pc existe
pkg-config --modversion sdl3
# Debería mostrar: 3.2.20 (o la versión que instalaste)

# Verificar los flags de compilación
pkg-config --cflags sdl3
# -I/usr/include/SDL3

# Verificar los flags de enlace
pkg-config --libs sdl3
# -lSDL3
```

---

## Resumen del proceso completo

```bash
# Todo en una secuencia
git clone https://github.com/libsdl-org/SDL.git SDL3-src
cd SDL3-src
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -- -j$(nproc)
sudo cmake --install build --prefix /usr
```

---

#sdl3 #compilacion #cmake #fuente #debian #bookworm
