# 06 - Compilar SDL3 desde Fuente

← [[05 - Dependencias de SDL3]] | Siguiente → [[07 - Configurar el Linker para SDL3]]

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

Ver lista completa en [[05 - Dependencias de SDL3]].

---

## Paso 2 — Descargar el código fuente de SDL3

### Opción A: Descargar una release estable (recomendado)

Ve a la página de releases de SDL3 en GitHub:
`https://github.com/libsdl-org/SDL/releases`

Descarga el archivo `.tar.gz` de la versión más reciente. A marzo de 2026, la versión estable es **3.2.20**.

```bash
# Crear directorio de trabajo
mkdir -p ~/sdl3-build && cd ~/sdl3-build

# Descargar (ajusta el número de versión si hay una más reciente)
wget https://github.com/libsdl-org/SDL/releases/download/release-3.2.20/SDL3-3.2.20.tar.gz

# Extraer
tar -xzf SDL3-3.2.20.tar.gz
cd SDL3-3.2.20
```

### Opción B: Clonar desde Git (versión de desarrollo)

```bash
git clone https://github.com/libsdl-org/SDL.git SDL3-src
cd SDL3-src
```

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
> Necesitarás configurar el linker para que encuentre SDL3. Ver [[07 - Configurar el Linker para SDL3]].

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
mkdir -p ~/sdl3-build && cd ~/sdl3-build
wget https://github.com/libsdl-org/SDL/releases/download/release-3.2.20/SDL3-3.2.20.tar.gz
tar -xzf SDL3-3.2.20.tar.gz
cd SDL3-3.2.20
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -- -j$(nproc)
sudo cmake --install build --prefix /usr
```

---

#sdl3 #compilacion #cmake #fuente #debian #bookworm
