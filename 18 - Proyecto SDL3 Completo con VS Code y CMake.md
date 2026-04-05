# 15 - Proyecto SDL3 Completo con VS Code y CMake

← [[17 - Compilar y Depurar con VS Code]] | Inicio → [[00 - Índice Principal]]

---

## Estructura del proyecto recomendada

```
mi-juego-sdl3/
├── .vscode/
│   ├── c_cpp_properties.json   ← IntelliSense
│   ├── tasks.json               ← Compilación
│   ├── launch.json              ← Depuración
│   └── settings.json            ← Preferencias del editor
├── src/
│   └── main.c
├── include/
│   └── (tus headers propios)
├── build/                       ← generado por CMake (no versionar)
└── CMakeLists.txt
```

---

## Paso 1 — Crear el proyecto

```bash
mkdir -p ~/mi-juego-sdl3/{src,include,.vscode}
cd ~/mi-juego-sdl3
```

---

## Paso 2 — Crear los archivos de código

### `src/main.c`

```c
#include <SDL3/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "SDL_Init error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Mi Juego SDL3", 800, 600, 0);
    SDL_Renderer *ren = SDL_CreateRenderer(win, NULL);

    int running = 1;
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) running = 0;
            if (e.type == SDL_EVENT_KEY_DOWN &&
                e.key.key == SDLK_ESCAPE) running = 0;
        }
        SDL_SetRenderDrawColor(ren, 30, 30, 46, 255);
        SDL_RenderClear(ren);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
```

### `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.16)
project(MiJuegoSDL3 VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Directorio de build para los ejecutables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Buscar SDL3
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

# Ejecutable
add_executable(mi_juego src/main.c)

# Enlazar SDL3
target_link_libraries(mi_juego PRIVATE SDL3::SDL3)

# Flags de compilación según el tipo de build
target_compile_options(mi_juego PRIVATE
    $<$<CONFIG:Debug>:-Wall -Wextra -g>
    $<$<CONFIG:Release>:-O2>
)
```

---

## Paso 3 — Archivos de configuración de VS Code

### `.vscode/c_cpp_properties.json`

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
            "intelliSenseMode": "linux-gcc-x64",
            "configurationProvider": "ms-vscode.cmake-tools"
        }
    ],
    "version": 4
}
```

> [!note] `configurationProvider`
> Si usas la extensión **CMake Tools**, puedes añadir `"configurationProvider": "ms-vscode.cmake-tools"` para que IntelliSense use automáticamente la configuración de CMake, incluyendo los includes de SDL3.

---

### `.vscode/tasks.json`

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "CMake: Configure",
            "type": "shell",
            "command": "cmake",
            "args": [
                "-S", "${workspaceFolder}",
                "-B", "${workspaceFolder}/build",
                "-DCMAKE_BUILD_TYPE=Debug"
            ],
            "group": "build",
            "presentation": { "reveal": "always" },
            "problemMatcher": []
        },
        {
            "label": "CMake: Build Debug",
            "type": "shell",
            "command": "cmake",
            "args": [
                "--build", "${workspaceFolder}/build",
                "--", "-j4"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "dependsOn": "CMake: Configure",
            "presentation": { "reveal": "always" },
            "problemMatcher": "$gcc"
        },
        {
            "label": "CMake: Build Release",
            "type": "shell",
            "command": "bash",
            "args": [
                "-c",
                "cmake -S ${workspaceFolder} -B ${workspaceFolder}/build -DCMAKE_BUILD_TYPE=Release && cmake --build ${workspaceFolder}/build -- -j$(nproc)"
            ],
            "group": "build",
            "problemMatcher": "$gcc"
        },
        {
            "label": "Limpiar build",
            "type": "shell",
            "command": "rm",
            "args": ["-rf", "${workspaceFolder}/build"],
            "group": "build"
        }
    ]
}
```

---

### `.vscode/launch.json`

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug con GDB (CMake)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/mi_juego",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/bin/gdb",
            "setupCommands": [
                {
                    "description": "Pretty-printing GDB",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "CMake: Build Debug"
        }
    ]
}
```

---

### `.vscode/settings.json`

```json
{
    "editor.tabSize": 4,
    "editor.insertSpaces": true,
    "editor.formatOnSave": true,
    "editor.bracketPairColorization.enabled": true,
    "C_Cpp.default.cStandard": "c17",
    "cmake.buildDirectory": "${workspaceFolder}/build",
    "cmake.configureOnOpen": false,
    "files.exclude": {
        "build/": true
    }
}
```

---

## Paso 4 — Abrir el proyecto en VS Code

```bash
cd ~/mi-juego-sdl3
code .
```

---

## Paso 5 — Flujo de trabajo diario

| Acción | Método |
|--------|--------|
| Compilar | `Ctrl+Shift+B` |
| Iniciar debug | `F5` |
| Poner breakpoint | Clic en margen o `F9` |
| Step over | `F10` |
| Step into | `F11` |
| Continuar | `F5` |
| Parar debug | `Shift+F5` |
| Terminal integrada | `` Ctrl+` `` |
| Paleta de comandos | `Ctrl+Shift+P` |

---

## Verificar que todo funciona

1. Abre el proyecto: `code ~/mi-juego-sdl3`
2. Comprueba que `#include <SDL3/SDL.h>` no tiene subrayado rojo
3. Escribe `SDL_` y verifica que aparece autocompletado
4. Pulsa `Ctrl+Shift+B` → el proyecto debe compilar sin errores
5. Pulsa `F5` → debe abrirse una ventana SDL3 y el depurador de VS Code

---

> [!success] Entorno completo configurado
> Si todos los pasos funcionaron, tienes un entorno profesional de desarrollo en C con SDL3 en Debian, con IntelliSense, compilación con un atajo de teclado y depuración integrada con GDB.

---

#vscode #cmake #sdl3 #proyecto #estructura #debug #gdb #completo
