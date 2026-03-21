# 02 - Instalacion de SDL3 con pacman

tags: #sdl3 #pacman #msys2 #instalacion

---

## Librerias disponibles en pacman (UCRT64)

Al buscar con `pacman -Ss sdl3` estos son los paquetes disponibles para UCRT64:

| Paquete | Version | Estado |
|---|---|---|
| `mingw-w64-ucrt-x86_64-sdl3` | 3.4.2 | Disponible |
| `mingw-w64-ucrt-x86_64-sdl3-image` | 3.4.0 | Disponible |
| `mingw-w64-ucrt-x86_64-sdl3-ttf` | 3.2.2 | Disponible |
| SDL3_mixer | — | No empaquetado, compilar desde fuente |
| SDL3_net | — | No empaquetado, compilar desde fuente |

---

## Instalacion

Desde la terminal **UCRT64**:

```bash
pacman -S mingw-w64-ucrt-x86_64-sdl3 \
          mingw-w64-ucrt-x86_64-sdl3-image \
          mingw-w64-ucrt-x86_64-sdl3-ttf
```

Confirma con `Y` cuando pregunte.

---

## Verificacion

```bash
ls /ucrt64/lib/libSDL3.a
ls /ucrt64/lib/libSDL3_image.a
ls /ucrt64/lib/libSDL3_ttf.a
```

Los tres deben responder con la ruta sin error.

---

## Siguiente paso

SDL3_mixer y SDL3_net deben compilarse manualmente:

- [03-Compilar SDL3_mixer desde fuente](03-Compilar_SDL3_mixer_desde_fuente)
- [04-Compilar SDL3_net desde fuente](04-Compilar_SDL3_net_desde_fuente)

---

## Referencias

- [README](README)
- [01-Instalacion de MSYS2 y GCC](01-Instalacion_de_MSYS2_y_GCC)
