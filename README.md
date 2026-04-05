# 🗂️ Entorno C + SDL3 en Debian

> Guía completa para configurar un entorno de desarrollo en C con SDL3 sobre Debian.

---

## 📌 Notas de este vault

| Nota | Descripción |
|------|-------------|
| [[01 - Introducción y Requisitos]] | Qué necesitas antes de empezar |
| [[02_-_Instalar_el_Compilador_GCC]] | Instalación de GCC y herramientas esenciales |
| [[03 - Verificar la Instalación de GCC]] | Comprobar que GCC funciona correctamente |
| [[04 - Instalar SDL3 en Debian]] | Cómo instalar SDL3 según tu versión de Debian |
| [[08_-_Dependencias_de_SDL3]] | Lista de dependencias necesarias para compilar SDL3 |
| [[09_-_Compilar_SDL3_desde_Fuente]] | Proceso completo de compilación e instalación manual |
| [[10_-_Configurar_el_Linker_para_SDL3]] | Hacer que el sistema encuentre la librería SDL3 |
| [[11_-_Primer_Programa_con_SDL3]] | Hola mundo con SDL3 en C |
| [[12_-_Compilar_un_Proyecto_con_SDL3]] | Comandos GCC y uso de CMake con SDL3 |
| [[13_-_Errores_Comunes_y_Soluciones]] | Troubleshooting frecuente |

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
> Si usas **Debian 12 Bookworm**, ve directamente a [[09_-_Compilar_SDL3_desde_Fuente]].
> Si usas **Debian 13 Trixie**, puedes instalar SDL3 con `apt` siguiendo [[04 - Instalar SDL3 en Debian]].

#debian #c #sdl3 #gcc #compilador
