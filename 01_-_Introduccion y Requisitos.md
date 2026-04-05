# 01 - Introducción y Requisitos

← [[00 - Índice Principal]] | Siguiente → [[02_-_Instalar_el_Compilador_GCC]]

---

## ¿Qué es GCC?

**GCC** (GNU Compiler Collection) es el compilador estándar de C en sistemas Linux. Soporta múltiples lenguajes: C, C++, Fortran, Ada, Go y más. Es el compilador sobre el que se construye el kernel de Linux y la mayoría del software de sistema GNU.

## ¿Qué es SDL3?

**SDL3** (Simple DirectMedia Layer 3) es una librería multimedia multiplataforma de código abierto que da acceso de bajo nivel a:

- 🖥️ Ventanas y renderizado 2D/3D (OpenGL, Vulkan, Metal)
- 🎵 Audio (ALSA, PulseAudio, PipeWire)
- ⌨️ Teclado, ratón y gamepad
- 🖱️ Eventos del sistema

SDL3 es la nueva generación de SDL2, con API modernizada, mejor soporte para GPU y mejoras en rendimiento.

---

## Versiones de Debian soportadas

| Versión | Codename | GCC disponible | SDL3 via apt |
|---------|----------|----------------|--------------|
| Debian 12 | Bookworm (oldstable) | GCC 12.2 | ❌ Solo desde fuente |
| Debian 13 | Trixie (stable) | GCC 14.2 | ✅ `libsdl3-dev` |
| Debian 14 | Forky (testing) | GCC 15.x | ✅ `libsdl3-dev` |

> [!warning] Importante
> En **Debian 12 Bookworm**, SDL3 **no está disponible como paquete apt**. Debes compilarla manualmente desde el código fuente. Ver [[09_-_Compilar_SDL3_desde_Fuente]].

---

## Requisitos previos

Antes de comenzar necesitas:

- Acceso a una terminal con permisos `sudo`
- Conexión a Internet para descargar paquetes
- Al menos **1 GB de espacio libre** en disco (para SDL3 desde fuente)
- Debian 12, 13 o superior

### Verificar tu versión de Debian

```bash
cat /etc/os-release
```

Salida esperada (ejemplo para Trixie):
```
PRETTY_NAME="Debian GNU/Linux 13 (trixie)"
NAME="Debian GNU/Linux"
VERSION_ID="13"
VERSION="13 (trixie)"
```

---

## Flujo de instalación

```
┌─────────────────────────────────────┐
│         ¿Qué versión de Debian?     │
└───────────────┬─────────────────────┘
                │
       ┌────────┴────────┐
       ▼                 ▼
  Bookworm (12)     Trixie (13+)
       │                 │
       ▼                 ▼
  Compilar SDL3     apt install
  desde fuente      libsdl3-dev
       │                 │
       └────────┬────────┘
                ▼
       Instalar GCC primero
```

---

#debian #requisitos #gcc #sdl3 #introduccion
