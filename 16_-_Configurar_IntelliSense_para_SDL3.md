# 13 - Configurar IntelliSense para SDL3

← [[15_-_Extensiones_para_C_y_SDL3_en_VS_Code]] | Siguiente → [[17_-_Compilar_y_Depurar_con_VS_Code]]

---

## ¿Qué es IntelliSense?

IntelliSense es el sistema de asistencia de código de VS Code. Para C, se encarga de:
- Autocompletar nombres de funciones y tipos de SDL3
- Mostrar la firma de funciones al escribirlas
- Subrayar errores antes de compilar
- Permitir "Ir a definición" (`F12`) en los headers de SDL3

Para que funcione correctamente con SDL3, hay que indicarle a VS Code dónde están los headers.

---

## El archivo `c_cpp_properties.json`

Este archivo configura el comportamiento de IntelliSense. Se ubica en `.vscode/c_cpp_properties.json` dentro de tu proyecto.

### Crear la carpeta de configuración

```bash
mkdir -p ~/mi-proyecto-sdl3/.vscode
cd ~/mi-proyecto-sdl3
```

---

## Configuración para SDL3 instalado en `/usr` (Trixie via apt)

Si instalaste SDL3 con `apt install libsdl3-dev` en Debian 13, los headers están en `/usr/include/SDL3`. Esta es la configuración más simple:

**`.vscode/c_cpp_properties.json`:**

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/include/SDL3"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```

---

## Configuración para SDL3 compilado en `/usr/local` (Bookworm desde fuente)

Si compilaste SDL3 desde fuente e instalaste en `/usr/local`:

**`.vscode/c_cpp_properties.json`:**

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/local/include/SDL3",
                "/usr/local/include"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```

---

## Generar `c_cpp_properties.json` desde VS Code

También puedes generarlo desde la interfaz de VS Code:

1. Abrir VS Code en tu proyecto: `code .`
2. Abrir la paleta de comandos: `Ctrl+Shift+P`
3. Escribir: `C/C++: Edit Configurations (UI)`
4. Se abre una pantalla gráfica donde puedes:
   - Seleccionar el compilador GCC
   - Añadir rutas a `Include Path`
   - Elegir el estándar C

O con la opción JSON directamente:
- `Ctrl+Shift+P` → `C/C++: Edit Configurations (JSON)`

---

## Localizar los headers de SDL3 en tu sistema

Si no sabes exactamente dónde está `SDL.h`:

```bash
find /usr -name "SDL.h" 2>/dev/null
# /usr/include/SDL3/SDL.h       ← apt en Trixie
# /usr/local/include/SDL3/SDL.h ← compilado desde fuente
```

Usa esa ruta en el campo `includePath` del JSON.

---

## Verificar que IntelliSense funciona

1. Abre `main.c` en VS Code
2. Escribe `#include <SDL3/SDL.h>` — no debe aparecer subrayado en rojo
3. Después de `SDL_`, VS Code debe mostrar autocompletado con funciones de SDL3
4. Haz clic sobre `SDL_Init` y pulsa `F12` — debe navegar al header

Si el `#include` sigue subrayado en rojo tras guardar el JSON:
- Revisa que la ruta del `includePath` es correcta
- Reinicia VS Code: `Ctrl+Shift+P` → `Developer: Reload Window`

---

## Configuración completa de `settings.json` (opcional)

Para ajustar el comportamiento general de VS Code en el proyecto, crea `.vscode/settings.json`:

```json
{
    "editor.tabSize": 4,
    "editor.insertSpaces": true,
    "editor.formatOnSave": true,
    "C_Cpp.default.cStandard": "c17",
    "C_Cpp.default.compilerPath": "/usr/bin/gcc",
    "files.associations": {
        "*.h": "c"
    },
    "editor.bracketPairColorization.enabled": true
}
```

---

#vscode #intellisense #sdl3 #cppproperties #headers #configuracion
