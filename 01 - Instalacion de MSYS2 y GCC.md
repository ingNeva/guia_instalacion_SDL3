# 01 - Instalacion de MSYS2 y GCC

tags: #msys2 #gcc #instalacion #cpp

---

## 1. Descargar e instalar MSYS2

Descarga el instalador desde [msys2.org](https://www.msys2.org/) y ejecutalo. La ruta de instalacion por defecto es:

```
C:\msys64
```

---

## 2. Terminal correcta: UCRT64

MSYS2 instala varias terminales. La unica que debes usar para desarrollo C++ es **MSYS2 UCRT64**.

Ubicacion en el menu inicio:
```
Inicio → MSYS2 → MSYS2 UCRT64
```

El prompt correcto se ve asi:
```
usuario@PC UCRT64 ~
$
```

> [!warning] Error comun
> Si el prompt dice `MSYS` en lugar de `UCRT64`, estas en la terminal incorrecta. `g++` no estara disponible ahi.

---

## 3. Actualizar el sistema base

Abre MSYS2 UCRT64 y ejecuta:

```bash
pacman -Syu
```

Si pide cerrar la terminal, cierrala, vuelve a abrirla y ejecuta:

```bash
pacman -Su
```

---

## 4. Instalar GCC / G++

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb mingw-w64-ucrt-x86_64-make
```

Verifica la instalacion:

```bash
g++ --version
```

Debe mostrar algo como:
```
g++ (GCC) 15.2.0
```

---

## 5. Agregar MSYS2 al PATH de Windows

Esto permite que VS Code y PowerShell encuentren el compilador.

1. Abre **Variables de entorno del sistema** (busca "variables de entorno" en el menu inicio)
2. En **Variables del sistema** selecciona `Path` → **Editar**
3. Agrega estas dos entradas:

```
C:\msys64\ucrt64\bin
C:\msys64\usr\bin
```

4. Acepta todo y reinicia VS Code

---

## Referencias

- [[00 - Indice]]
- [[02 - Instalacion de SDL3 con pacman]]
