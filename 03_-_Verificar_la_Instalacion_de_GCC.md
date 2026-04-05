# 03 - Verificar la Instalación de GCC

← [[02_-_Instalar_el_Compilador_GCC]] | Siguiente → [[04 - Instalar SDL3 en Debian]]

---

## Verificar que GCC está instalado

### Comprobar la versión

```bash
gcc --version
```

Salida esperada (ejemplo en Debian 13 Trixie):
```
gcc (Debian 14.2.0-7) 14.2.0
Copyright (C) 2024 Free Software Foundation, Inc.
```

Salida esperada (ejemplo en Debian 12 Bookworm):
```
gcc (Debian 12.2.0-14) 12.2.0
Copyright (C) 2022 Free Software Foundation, Inc.
```

---

### Localizar el binario

```bash
which gcc
# /usr/bin/gcc

whereis gcc
# gcc: /usr/bin/gcc /usr/lib/gcc /usr/share/gcc /usr/share/man/man1/gcc.1.gz
```

---

### Verificar también `make` y `cmake`

```bash
make --version
# GNU Make 4.x ...

cmake --version
# cmake version 3.x.x
```

---

## Compilar un programa de prueba

Esta es la verificación más importante: comprobar que GCC puede compilar código C real.

### Paso 1 — Crear el archivo fuente

```bash
nano hola.c
```

Contenido del archivo:

```c
#include <stdio.h>

int main(void) {
    printf("¡Hola, Debian! GCC funciona correctamente.\n");
    return 0;
}
```

### Paso 2 — Compilar

```bash
gcc hola.c -o hola
```

### Paso 3 — Ejecutar

```bash
./hola
```

Salida esperada:
```
¡Hola, Debian! GCC funciona correctamente.
```

---

## Flags de compilación útiles

| Flag | Descripción |
|------|-------------|
| `-Wall` | Activa todos los warnings comunes |
| `-Wextra` | Warnings adicionales |
| `-g` | Incluye información de depuración (para GDB) |
| `-O2` | Optimización nivel 2 |
| `-std=c11` | Usar estándar C11 |
| `-std=c17` | Usar estándar C17 (recomendado) |
| `-o nombre` | Nombre del archivo de salida |

### Ejemplo con flags recomendados para desarrollo

```bash
gcc -Wall -Wextra -g -std=c17 hola.c -o hola
```

---

> [!success] ¡Listo!
> Si el programa compiló y ejecutó correctamente, GCC está instalado y funciona. Ahora puedes pasar a instalar SDL3.

---

#gcc #verificacion #compilacion #debug #flags
