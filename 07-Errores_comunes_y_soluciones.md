# 07 - Errores comunes y soluciones

tags: #errores #debug #troubleshooting #sdl3

---

## Error: `g++: command not found` en terminal MSYS

**Mensaje:**
```
bash: g++: command not found
```

**Causa:** Estas usando la terminal `MSYS` base en lugar de `UCRT64`.

**Solucion:** Cierra la terminal y abre **MSYS2 UCRT64** desde el menu inicio. El prompt debe mostrar `UCRT64`, no `MSYS`.

Alternativa desde cualquier terminal MSYS abierta:
```bash
MSYSTEM=UCRT64 exec bash --login
```

---

## Error: `g++` no se reconoce en PowerShell

**Mensaje:**
```
g++ : El termino 'g++' no se reconoce como nombre de un cmdlet...
```

**Causa:** PowerShell no tiene MSYS2 en el PATH, o VS Code esta usando PowerShell en lugar de bash.

**Soluciones:**

1. Agregar al PATH del sistema:
   ```
   C:\msys64\ucrt64\bin
   C:\msys64\usr\bin
   ```

2. Cambiar la terminal de VS Code a MSYS2 UCRT64 en `settings.json`:
   ```json
   "terminal.integrated.defaultProfile.windows": "MSYS2 UCRT64"
   ```

---

## Error: `Could not find CMakeLists.txt for ogg`

**Mensaje:**
```
CMake Error: Could not find CMakeLists.txt for ogg in external/ogg.
Run the download script in the external folder, or re-configure with
-DSDLMIXER_VENDORED=OFF
```

**Causa:** El repositorio de SDL_mixer se clono sin sus submódulos.

**Solucion:** Dentro de la carpeta `SDL_mixer`:
```bash
git submodule update --init --recursive
```

Luego volver a ejecutar el comando cmake.

---

## Error: `undefined reference to SDL_Init` (y otras funciones SDL)

**Mensaje:**
```
undefined reference to `SDL_Init'
undefined reference to `SDL_CreateWindow'
...
collect2.exe: error: ld returned 1 exit status
```

**Causa:** VS Code esta usando su tarea por defecto ("C/C++: g++.exe build active file") que no incluye los flags `-lSDL3` ni las rutas de las librerias.

**Solucion:**
1. Verificar que existe `.vscode/tasks.json` con la tarea "Compilar con SDL3"
2. Ir a `Ctrl+Shift+P` → **Tasks: Configure Default Build Task** → seleccionar **"Compilar con SDL3"**
3. Asegurarse de que VS Code tiene abierta la **carpeta** del proyecto, no solo el archivo suelto

---

## Error: `No such file or directory` con rutas Windows en bash

**Mensaje:**
```
cc1plus.exe: fatal error: C:UsersliaDocumentosProyectos/main.cpp: No such file or directory
```

**Causa:** Bash interpreta los backslashes de rutas Windows (`C:\Users\...`) como caracteres de escape, eliminandolos.

**Solucion:** Usar `cygpath` en el `tasks.json` para convertir la ruta antes de pasarsela a g++:

```json
"command": "cd $(cygpath -u '${fileDirname}') && g++ -g '${fileBasename}' -o '${fileBasenameNoExtension}.exe' ..."
```

---

## Error: el `.exe` compila pero no ejecuta (DLL no encontrada)

**Sintoma:** El archivo `.exe` se genera correctamente pero al hacer doble clic o ejecutarlo fuera de la terminal MSYS2 no abre nada, o muestra un error de DLL faltante.

**Causa:** Windows no encuentra las DLLs de SDL3 porque no estan junto al ejecutable ni en el PATH.

**Solucion:** Copiar desde `C:\msys64\ucrt64\bin\` a la carpeta del proyecto:
```
SDL3.dll
SDL3_image.dll
SDL3_ttf.dll
SDL3_mixer.dll
SDL3_net.dll
```

---

## Error 1696 de IntelliSense (`#include errors detected`)

**Mensaje:**
```
#include errors detected. Please update your includePath.
```

**Causa:** El archivo `c_cpp_properties.json` no esta siendo detectado, o VS Code no tiene abierta la carpeta correcta como workspace.

**Nota:** Este error es solo visual (subrayado rojo). No impide compilar.

**Solucion:**
1. Verificar que VS Code abrio la carpeta raiz del proyecto (no un archivo suelto)
2. Verificar que `.vscode/c_cpp_properties.json` existe con las rutas correctas:
   ```json
   "includePath": [
     "${workspaceFolder}/**",
     "C:/msys64/ucrt64/include",
     "C:/msys64/ucrt64/include/SDL3"
   ]
   ```
3. `Ctrl+Shift+P` → **C/C++: Edit Configurations (UI)** para verificar visualmente

---

## Referencias

- [[README]]
- [[05-Configurar_VS_Code]]
- [[06-Plantilla_de_proyecto]]
