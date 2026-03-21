# 04 - Compilar SDL3_net desde fuente

tags: #sdl3 #net #cmake #compilacion

---

## Por que compilar desde fuente

SDL3_net tampoco esta disponible como paquete en MSYS2. Se compila de forma similar a SDL3_mixer pero es mas sencillo porque no tiene dependencias externas.

---

## 1. Clonar el repositorio

Desde `/c/sdl3_build` (ya creada al compilar mixer):

```bash
cd /c/sdl3_build
git clone https://github.com/libsdl-org/SDL_net.git
cd SDL_net
```

> [!info]
> SDL_net no necesita `git submodule update` porque no tiene dependencias vendored.

---

## 2. Configurar, compilar e instalar

```bash
cmake -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=/ucrt64

cmake --build build
cmake --install build
```

---

## 3. Verificar

```bash
ls /ucrt64/lib/libSDL3_net.dll.a
ls /ucrt64/bin/SDL3_net.dll
ls /ucrt64/include/SDL3_net/SDL_net.h
```

> [!info] Nota sobre el archivo estatico
> SDL3_net instala `libSDL3_net.dll.a` (enlace dinamico) en lugar de `libSDL3_net.a` (estatico). Esto es normal y funciona igual con el flag `-lSDL3_net` en g++.

---

## Archivos generados

| Archivo | Ubicacion | Uso |
|---|---|---|
| `libSDL3_net.dll.a` | `/ucrt64/lib/` | Enlace en compilacion |
| `SDL3_net.dll` | `/ucrt64/bin/` | Ejecucion en Windows |
| `SDL_net.h` | `/ucrt64/include/SDL3_net/` | Header para incluir |

---

## Verificacion final de todas las librerias

```bash
ls /ucrt64/lib/libSDL3.a
ls /ucrt64/lib/libSDL3_image.a
ls /ucrt64/lib/libSDL3_ttf.a
ls /ucrt64/lib/libSDL3_mixer.dll.a
ls /ucrt64/lib/libSDL3_net.dll.a
```

Cuando todas responden sin error, el entorno de librerias esta completo.

---

## Referencias

- [[00 - Indice]]
- [[05 - Configurar VS Code]]
