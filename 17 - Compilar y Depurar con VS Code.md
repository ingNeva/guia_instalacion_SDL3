# 14 - Compilar y Depurar con VS Code

← [[16 - Configurar IntelliSense para SDL3]] | Siguiente → [[18 - Proyecto SDL3 Completo con VS Code y CMake]]

---

## Los tres archivos de configuración de VS Code

```
.vscode/
├── c_cpp_properties.json  → IntelliSense (ya configurado en [[13]])
├── tasks.json             → Cómo COMPILAR el proyecto
└── launch.json            → Cómo EJECUTAR y DEPURAR el proyecto
```

---

## `tasks.json` — Configurar la compilación

El archivo `tasks.json` define tareas que VS Code puede ejecutar. La más importante es la tarea de compilación (build).

Crea `.vscode/tasks.json`:

### Para proyectos de un solo archivo con GCC + SDL3

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build con GCC + SDL3",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-Wall",
                "-Wextra",
                "-g",
                "-std=c17",
                "${workspaceFolder}/main.c",
                "-o",
                "${workspaceFolder}/mi_juego",
                "-I/usr/include/SDL3",
                "-lSDL3"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "presentation": {
                "reveal": "always",
                "panel": "shared"
            },
            "problemMatcher": "$gcc"
        },
        {
            "label": "Build Release (optimizado)",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-O2",
                "-std=c17",
                "${workspaceFolder}/main.c",
                "-o",
                "${workspaceFolder}/mi_juego",
                "-I/usr/include/SDL3",
                "-lSDL3"
            ],
            "group": "build",
            "problemMatcher": "$gcc"
        }
    ]
}
```

> [!tip] Usar `pkg-config` en tasks.json
> Para que VS Code use `pkg-config` automáticamente, cambia el `command` a `bash` y el `args` a un comando completo:
> ```json
> "command": "bash",
> "args": [
>     "-c",
>     "gcc -Wall -Wextra -g -std=c17 ${workspaceFolder}/main.c -o ${workspaceFolder}/mi_juego $(pkg-config --cflags --libs sdl3)"
> ]
> ```

### Si SDL3 está en `/usr/local` (compilada desde fuente)

Cambia los args de la ruta:
```json
"-I/usr/local/include/SDL3",
"-L/usr/local/lib",
"-lSDL3"
```

### Atajos para ejecutar la tarea de build

| Atajo | Acción |
|-------|--------|
| `Ctrl+Shift+B` | Ejecutar la tarea de build por defecto |
| `Ctrl+Shift+P` → "Run Task" | Ver todas las tareas disponibles |

---

## `launch.json` — Configurar la depuración con GDB

Crea `.vscode/launch.json`:

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug mi_juego (GDB)",
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
                    "description": "Activar pretty-printing en GDB",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "Desactivar paginación de GDB",
                    "text": "set pagination off",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "Build con GCC + SDL3",
            "logging": {
                "engineLogging": false
            }
        }
    ]
}
```

### Campos clave de `launch.json`

| Campo | Descripción |
|-------|-------------|
| `program` | Ruta al ejecutable compilado |
| `preLaunchTask` | Nombre exacto de la tarea en `tasks.json` |
| `MIMode` | `"gdb"` para usar GDB en Linux |
| `miDebuggerPath` | Ruta al ejecutable de GDB |
| `stopAtEntry` | `true` = pausar al entrar a `main()` |
| `externalConsole` | `false` = usar terminal integrada de VS Code |

---

## Flujo de trabajo de depuración

### 1. Compilar

Presiona `Ctrl+Shift+B` o ve a **Terminal → Run Build Task**.

En la terminal integrada de VS Code verás la salida del compilador.

### 2. Poner breakpoints

Haz clic en el margen izquierdo del editor (junto al número de línea) para añadir un breakpoint (aparece un círculo rojo).

### 3. Iniciar la depuración

Presiona `F5` o ve a **Run → Start Debugging**.

VS Code compilará automáticamente (gracias a `preLaunchTask`) y lanzará el depurador.

### 4. Controles durante la depuración

| Tecla | Acción |
|-------|--------|
| `F5` | Continuar hasta el siguiente breakpoint |
| `F10` | Step Over (siguiente línea, sin entrar a funciones) |
| `F11` | Step Into (entrar a la función) |
| `Shift+F11` | Step Out (salir de la función actual) |
| `F9` | Activar/desactivar breakpoint en la línea actual |
| `Shift+F5` | Detener la depuración |

### 5. Paneles de depuración

- **Variables** → valores de variables locales y globales en tiempo real
- **Watch** → expresiones que quieres monitorear manualmente
- **Call Stack** → pila de llamadas de funciones
- **Breakpoints** → lista de todos los puntos de interrupción activos
- **Debug Console** → consola de GDB para ejecutar comandos manuales

---

## Ejecutar sin depurar

Si solo quieres ejecutar el programa sin el depurador:

```bash
# Desde la terminal integrada de VS Code (Ctrl+`)
./mi_juego
```

O crea una tarea adicional en `tasks.json`:

```json
{
    "label": "Ejecutar mi_juego",
    "type": "shell",
    "command": "${workspaceFolder}/mi_juego",
    "group": "test",
    "dependsOn": "Build con GCC + SDL3"
}
```

---

#vscode #gdb #debug #tasks #launch #compilar #depurar #sdl3
