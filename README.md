# 🗂️ Entorno C + SDL3 en Debian

> Guía completa para configurar un entorno de desarrollo en C con SDL3 sobre Debian.

---

## 📌 Notas de este vault

| Nota                                                                           | Descripción                                          |
| ------------------------------------------------------------------------------ | ---------------------------------------------------- |
| [01 - Introducción y Requisitos](01_-_Introduccion_y_Requisitos)               | Qué necesitas antes de empezar                       |
| [02 - Instalar el Compilador GCC](02_-_Instalar_el_Compilador_GCC)             | Instalación de GCC y herramientas esenciales         |
| [03 - Verificar la Instalación de GCC](03_-_Verificar_la_Instalacion_de_GCC)   | Comprobar que GCC funciona correctamente             |
| [04 - Instalar SDL3 en Debian](04_-_Instalar_SDL3_en_Debian)                   | Cómo instalar SDL3 según tu versión de Debian        |
| [05 - Compilar SDL3_mixer desde Fuente](05_-_Compilar_SDL3_mixer_desde_Fuente) | Instalación manual de SDL3_mixer (audio)             |
| [06 - Compilar SDL3_net desde Fuente](06_-_Compilar_SDL3_net_desde_Fuente)     | Instalación manual de SDL3_net (red)                 |
| [08 - Dependencias de SDL3](07_-_Dependencias_de_SDL3.md)                         | Lista de dependencias necesarias para compilar SDL3  |
| [09 - Compilar SDL3 desde Fuente](08_-_Compilar_SDL3_desde_Fuente.md)             | Proceso completo de compilación e instalación manual |
| [10 - Configurar el Linker para SDL3](09_-_Configurar_el_Linker_para_SDL3.md)     | Hacer que el sistema encuentre la librería SDL3      |
| [11 - Primer Programa con SDL3](10_-_Primer_Programa_con_SDL3.md)                 | Hola mundo con SDL3 en C                             |
| [12 - Compilar un Proyecto con SDL3](11_-_Compilar_un_Proyecto_con_SDL3.md)       | Comandos GCC y uso de CMake con SDL3                 |
| [13 - Errores Comunes y Soluciones](12_-_Errores_Comunes_y_Soluciones.md)         | Troubleshooting frecuente                            |

---

## 🔍 Estado actual de SDL3 en Debian (2025)

- **Debian 13 Trixie (estable)** → `libsdl3-dev` disponible vía `apt`  
- **Debian 12 Bookworm (oldstable)** → requiere compilar desde fuente
- **Versión actual de SDL3**: `3.2.10` (trixie) / `3.2.20` (forky/testing)

---

## 🛠️ Herramientas del stack

```
GCC  ──►  Compilador C
make ──►  Sistema de construcción clásico
CMake──►  Sistema de construcción moderno (requerido por SDL3)
GDB  ──►  Depurador
SDL3 ──►  Librería multimedia
```

---

> [!tip] Consejo
> Si usas **Debian 12 Bookworm**, ve directamente a [09 - Compilar SDL3 desde Fuente](08_-_Compilar_SDL3_desde_Fuente.md).
> Si usas **Debian 13 Trixie**, puedes instalar SDL3 con `apt` siguiendo [04 - Instalar SDL3 en Debian](04_-_Instalar_SDL3_en_Debian).

#debian #c #sdl3 #gcc #compilador
