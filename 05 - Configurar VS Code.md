# 05 - Configurar VS Code

tags: #vscode #configuracion #tasks #intellisense

---

## 1. Extension necesaria

Instala desde el marketplace de VS Code (`Ctrl+Shift+X`):

- **C/C++** — de Microsoft (IntelliSense, navegacion de codigo, depuracion)

---

## 2. Configurar la terminal integrada de VS Code

Por defecto VS Code usa PowerShell, que no encuentra `g++`. Hay que apuntarla a MSYS2 UCRT64.

Abre `Ctrl+Shift+P` → **Open User Settings JSON** y agrega:

```json
"terminal.integrated.profiles.windows": {
  "MSYS2 UCRT64": {
    "path": "C:\\msys64\\usr\\bin\\bash.exe",
    "args": ["--login", "-i"],
    "env": {
      "MSYSTEM": "UCRT64",
      "CHERE_INVOKING": "1"
    }
  }
},
"terminal.integrated.defaultProfile.windows": "MSYS2 UCRT64"
```

Reinicia VS Code despues de guardar.

---

## 3. Estructura de carpetas del proyecto

```
mi_proyecto/
├── .vscode/
│   ├── tasks.json
│   └── c_cpp_properties.json
├── main.cpp
└── SDL3.dll  (y demas DLLs)
```

> [!important]
> VS Code debe abrirse con **Archivo → Abrir carpeta**, apuntando a `mi_proyecto`. No abrir solo el archivo `main.cpp`.

---

## 4. Archivo tasks.json

Ubicacion: `.vscode/tasks.json`

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Compilar con SDL3",
      "type": "shell",
      "command": "cd $(cygpath -u '${fileDirname}') && g++ -g '${fileBasename}' -o '${fileBasenameNoExtension}.exe' -I /ucrt64/include -L /ucrt64/lib -lSDL3 -lSDL3_image -lSDL3_ttf -lSDL3_mixer -lSDL3_net -mwindows",
      "options": {
        "shell": {
          "executable": "C:\\msys64\\usr\\bin\\bash.exe",
          "args": ["--login", "-i", "-c"]
        },
        "env": {
          "MSYSTEM": "UCRT64",
          "CHERE_INVOKING": "1"
        }
      },
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": ["$gcc"],
      "detail": "Compilar archivo actual con SDL3 completo"
    }
  ]
}
```

> [!tip] Por que cygpath
> Las variables de VS Code como `${fileDirname}` generan rutas Windows con backslashes (`C:\Users\...`). Bash las interpreta mal. `cygpath -u` las convierte al formato Unix que bash entiende (`/c/Users/...`).

---

## 5. Archivo c_cpp_properties.json

Ubicacion: `.vscode/c_cpp_properties.json`

```json
{
  "configurations": [
    {
      "name": "Win32",
      "includePath": [
        "${workspaceFolder}/**",
        "C:/msys64/ucrt64/include",
        "C:/msys64/ucrt64/include/SDL3"
      ],
      "compilerPath": "C:/msys64/ucrt64/bin/g++.exe",
      "cStandard": "c17",
      "cppStandard": "c++17",
      "intelliSenseMode": "windows-gcc-x64"
    }
  ],
  "version": 4
}
```

---

## 6. Definir la tarea de build por defecto

Si VS Code no usa automaticamente la tarea correcta:

`Ctrl+Shift+P` → **Tasks: Configure Default Build Task** → selecciona **"Compilar con SDL3"**

---

## 7. Atajo de compilacion

```
Ctrl + Shift + B
```

Compila el archivo `.cpp` actualmente abierto en el editor.

---

## Referencias

- [[00 - Indice]]
- [[06 - Plantilla de proyecto]]
