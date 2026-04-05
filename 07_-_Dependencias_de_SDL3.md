# 07 - Dependencias de SDL3

← [06 - Compilar SDL3_net desde Fuente](06_-_Compilar_SDL3_net_desde_Fuente) | Siguiente → [08_-_Compilar_SDL3_desde_Fuente](08_-_Compilar_SDL3_desde_Fuente)

---

## ¿Por qué se necesitan dependencias?

SDL3 es una librería que puede interactuar con el sistema a muchos niveles: audio, video, entrada de dispositivos, etc. Para compilarla desde fuente con soporte completo, el sistema necesita los headers de desarrollo de todas esas subsistemas.

> [!note] Nota
> SDL3 enlaza dinámicamente contra muchas librerías en tiempo de ejecución. Si no tienes una instalada, esa funcionalidad simplemente se deshabilita sin errores de compilación. Pero para el desarrollo completo, conviene tenerlas todas.

---

## Comando completo de instalación de dependencias

Ejecuta este bloque completo en tu terminal (es el recomendado por la documentación oficial de SDL3):

```bash
sudo apt-get install -y \
  build-essential \
  git \
  make \
  pkg-config \
  cmake \
  ninja-build \
  gnome-desktop-testing \
  libasound2-dev \
  libpulse-dev \
  libaudio-dev \
  libfribidi-dev \
  libjack-dev \
  libsndio-dev \
  libx11-dev \
  libxext-dev \
  libxrandr-dev \
  libxcursor-dev \
  libxfixes-dev \
  libxi-dev \
  libxss-dev \
  libxtst-dev \
  libxkbcommon-dev \
  libdrm-dev \
  libgbm-dev \
  libgl1-mesa-dev \
  libgles2-mesa-dev \
  libegl1-mesa-dev \
  libdbus-1-dev \
  libibus-1.0-dev \
  libudev-dev \
  libthai-dev
```

### Para Debian 13 Trixie — añadir también:

```bash
sudo apt-get install -y \
  libpipewire-0.3-dev \
  libwayland-dev \
  libdecor-0-dev \
  liburing-dev
```

---

## Descripción de los grupos de dependencias

### Herramientas de construcción

| Paquete | Función |
|---------|---------|
| `build-essential` | GCC, make, headers de C |
| `cmake` | Sistema de build moderno |
| `ninja-build` | Backend rápido de cmake |
| `pkg-config` | Detección de flags de librerías |
| `git` | Para clonar el repositorio |

### Audio

| Paquete | Backend |
|---------|---------|
| `libasound2-dev` | ALSA (Linux Audio) |
| `libpulse-dev` | PulseAudio |
| `libaudio-dev` | NAS (Network Audio) |
| `libjack-dev` | JACK (audio pro/baja latencia) |
| `libsndio-dev` | sndio (audio de OpenBSD) |
| `libpipewire-0.3-dev` | PipeWire (moderno, Wayland) |

### Video / Gráficos / Ventanas X11

| Paquete | Función |
|---------|---------|
| `libx11-dev` | Display X11 base |
| `libxext-dev` | Extensiones X11 |
| `libxrandr-dev` | Resolución/rotación de pantalla |
| `libxcursor-dev` | Cursores del mouse |
| `libxfixes-dev` | Extensión XFixes |
| `libxi-dev` | Input extendido |
| `libxss-dev` | Screensaver |
| `libxtst-dev` | Testing de X |
| `libxkbcommon-dev` | Teclado en Wayland/X |

### Video / Gráficos / Mesa

| Paquete | Función |
|---------|---------|
| `libdrm-dev` | Direct Rendering Manager |
| `libgbm-dev` | Generic Buffer Manager |
| `libgl1-mesa-dev` | OpenGL (Mesa) |
| `libgles2-mesa-dev` | OpenGL ES 2.0 |
| `libegl1-mesa-dev` | EGL (interfaz GL/ventana) |

### Wayland

| Paquete | Función |
|---------|---------|
| `libwayland-dev` | Protocolo Wayland |
| `libdecor-0-dev` | Decoraciones de ventana en Wayland |

### Entrada / Sistema

| Paquete | Función |
|---------|---------|
| `libdbus-1-dev` | D-Bus (comunicación entre procesos) |
| `libibus-1.0-dev` | Método de entrada IBus |
| `libudev-dev` | udev (dispositivos del kernel) |
| `libthai-dev` | Soporte para idioma Thai |
| `libfribidi-dev` | Soporte para texto bidi (árabe/hebreo) |

---

> [!warning] Error frecuente
> Si ves `Package 'libfribidi-dev' has no installation candidate` en Bookworm, prueba sin ese paquete. SDL3 compilará igual con funcionalidad reducida.

---

#sdl3 #dependencias #apt #debian #audio #opengl #wayland #x11
