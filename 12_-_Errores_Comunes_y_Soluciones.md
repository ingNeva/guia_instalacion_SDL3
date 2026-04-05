# 10 - Errores Comunes y Soluciones

← [[11_-_Compilar_un_Proyecto_con_SDL3]] | Inicio → [[00 - Índice Principal]]

---

## Errores de compilación

### ❌ `fatal error: SDL3/SDL.h: No such file or directory`

**Causa:** El compilador no encuentra los headers de SDL3.

**Soluciones:**

```bash
# 1. Verificar que SDL3 está instalada
dpkg -l libsdl3-dev         # si usaste apt (Trixie)
ls /usr/include/SDL3/       # si compilaste desde fuente en /usr
ls /usr/local/include/SDL3/ # si compilaste desde fuente en /usr/local

# 2. Usar pkg-config para obtener el path correcto
gcc main.c -o app $(pkg-config --cflags --libs sdl3)

# 3. Si SDL3 está en /usr/local, indicarlo manualmente
gcc -I/usr/local/include/SDL3 main.c -o app -L/usr/local/lib -lSDL3
```

---

### ❌ `error: undefined reference to 'SDL_Init'`

**Causa:** El enlazador (linker) no encuentra la librería SDL3.

**Soluciones:**

```bash
# 1. Asegúrate de incluir -lSDL3 AL FINAL del comando
gcc main.c $(pkg-config --cflags --libs sdl3) -o app   # ✅ correcto
gcc $(pkg-config --libs sdl3) main.c -o app            # ❌ puede fallar

# 2. Verificar que la librería existe
ls /usr/lib/libSDL3*
ls /usr/local/lib/libSDL3*

# 3. Actualizar el caché del linker
sudo ldconfig
```

---

### ❌ `Package 'sdl3' was not found in the pkg-config search path`

**Causa:** `pkg-config` no sabe dónde está SDL3.

**Solución:**

```bash
# Si SDL3 está en /usr/local
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH
pkg-config --modversion sdl3

# Hacer permanente
echo 'export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH' >> ~/.bashrc
source ~/.bashrc
```

---

## Errores de ejecución

### ❌ `error while loading shared libraries: libSDL3.so.0: cannot open shared object file`

**Causa:** El programa no puede encontrar la librería SDL3 en tiempo de ejecución.

**Soluciones:**

```bash
# 1. Registrar la librería con ldconfig
echo "/usr/local/lib" | sudo tee /etc/ld.so.conf.d/sdl3.conf
sudo ldconfig

# 2. Verificar que fue registrada
ldconfig -p | grep SDL3

# 3. Alternativa temporal: LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
./mi_juego
```

---

### ❌ `Couldn't initialize SDL: No available video device`

**Causa:** SDL3 no puede encontrar un servidor de display (X11 o Wayland).

**Soluciones:**

```bash
# 1. Verificar que DISPLAY está definido (para X11)
echo $DISPLAY
# Debe mostrar algo como: :0

# 2. Si estás en SSH, conectar con reenvío X11
ssh -X usuario@servidor

# 3. Si estás en una terminal virtual (tty), lanzar una sesión gráfica primero
startx

# 4. Verificar que estás en una sesión Wayland
echo $WAYLAND_DISPLAY
# Debe mostrar: wayland-0
```

---

### ❌ `SDL_Init(): No available audio device`

**Causa:** No se encontró un dispositivo de audio. En sistemas sin audio (servidores), esto es normal.

**Solución:**

```bash
# Inicializar solo video si no necesitas audio
SDL_Init(SDL_INIT_VIDEO);   # en lugar de SDL_INIT_AUDIO
```

---

## Errores de CMake

### ❌ `Could not find a package configuration file provided by "SDL3"`

**Causa:** CMake no encuentra el archivo `SDL3Config.cmake`.

**Soluciones:**

```bash
# 1. Indicar el path manualmente
cmake -S . -B build -DCMAKE_PREFIX_PATH=/usr/local

# 2. O definir SDL3_DIR
cmake -S . -B build -DSDL3_DIR=/usr/local/lib/cmake/SDL3
```

---

## Verificación rápida del entorno

Ejecuta este script para diagnosticar tu entorno:

```bash
#!/bin/bash
echo "=== Entorno de desarrollo C + SDL3 ==="
echo ""
echo "GCC:"
gcc --version | head -1

echo ""
echo "CMake:"
cmake --version | head -1

echo ""
echo "SDL3 (pkg-config):"
pkg-config --modversion sdl3 2>/dev/null || echo "❌ No encontrada"

echo ""
echo "Librería SDL3 en sistema:"
ldconfig -p | grep SDL3 | head -3

echo ""
echo "Headers SDL3:"
ls /usr/include/SDL3/SDL.h 2>/dev/null && echo "✅ En /usr/include" || \
ls /usr/local/include/SDL3/SDL.h 2>/dev/null && echo "✅ En /usr/local/include" || \
echo "❌ No encontrada"
```

Guárdalo como `check-env.sh`, dale permisos y ejecútalo:

```bash
chmod +x check-env.sh
./check-env.sh
```

---

## Recursos útiles

- **Wiki oficial SDL3**: https://wiki.libsdl.org/SDL3/FrontPage
- **README Linux (dependencias)**: https://wiki.libsdl.org/SDL3/README-linux
- **README CMake**: https://wiki.libsdl.org/SDL3/README-cmake
- **Releases de SDL3**: https://github.com/libsdl-org/SDL/releases
- **Paquetes Debian**: https://packages.debian.org/search?keywords=libsdl3

---

#sdl3 #errores #troubleshooting #linker #gcc #cmake #debug
