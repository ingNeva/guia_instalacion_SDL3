# 03 - Compilar SDL3_mixer desde fuente

tags: #sdl3 #mixer #cmake #compilacion

---

## Por que compilar desde fuente

SDL3_mixer no esta disponible como paquete en los repositorios de MSYS2. Debe compilarse manualmente desde el repositorio oficial de libsdl-org.

---

## 1. Instalar dependencias de compilacion

Desde la terminal **UCRT64**:

```bash
pacman -S mingw-w64-ucrt-x86_64-cmake \
          mingw-w64-ucrt-x86_64-ninja \
          mingw-w64-ucrt-x86_64-git
```

---

## 2. Crear carpeta de trabajo y clonar

```bash
mkdir /c/sdl3_build
cd /c/sdl3_build
git clone https://github.com/libsdl-org/SDL_mixer.git
cd SDL_mixer
```

---

## 3. Descargar submódulos (paso critico)

> [!warning] Error si omites este paso
> Sin este comando, cmake falla con:
> `Could not find CMakeLists.txt for ogg in external/ogg`

```bash
git submodule update --init --recursive
```

Esto descarga libogg, libvorbis, libFLAC, mpg123 y demas dependencias de audio. Puede tardar varios minutos.

---

## 4. Configurar con CMake

```bash
cmake -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=/ucrt64 \
  -DSDLMIXER_VENDORED=ON
```

El flag `-DSDLMIXER_VENDORED=ON` le indica a SDL_mixer que use las dependencias descargadas con git submodule, sin necesidad de instalarlas por separado.

---

## 5. Compilar e instalar

```bash
cmake --build build
cmake --install build
```

La compilacion puede tardar entre 2 y 5 minutos.

---

## 6. Verificar

```bash
ls /ucrt64/lib/libSDL3_mixer.dll.a
ls /ucrt64/bin/SDL3_mixer.dll
ls /ucrt64/include/SDL3/SDL_mixer.h
```

---

## Archivos generados

| Archivo | Ubicacion | Uso |
|---|---|---|
| `libSDL3_mixer.dll.a` | `/ucrt64/lib/` | Enlace en compilacion |
| `SDL3_mixer.dll` | `/ucrt64/bin/` | Ejecucion en Windows |
| `SDL_mixer.h` | `/ucrt64/include/SDL3/` | Header para incluir |

---

## Referencias

- [README](README)
- [04-Compilar SDL3_net desde fuente](04-Compilar_SDL3_net_desde_fuente)
