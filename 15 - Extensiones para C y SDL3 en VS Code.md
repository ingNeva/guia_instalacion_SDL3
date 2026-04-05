# 12 - Extensiones para C y SDL3 en VS Code

← [[14 - Instalar Visual Studio Code en Debian]] | Siguiente → [[16 - Configurar IntelliSense para SDL3]]

---

## Extensiones esenciales

### 1. C/C++ (Microsoft) — OBLIGATORIA

La extensión oficial de Microsoft para C y C++. Proporciona:
- IntelliSense (autocompletado, sugerencias de tipo)
- Navegación de código (ir a definición, referencias)
- Depuración integrada con GDB
- Resaltado de sintaxis avanzado

**Instalar desde el terminal:**

```bash
code --install-extension ms-vscode.cpptools
```

**O desde la interfaz:**
- Abrir VS Code → `Ctrl+Shift+X` → buscar **"C/C++"** → instalar la de Microsoft

---

### 2. C/C++ Extension Pack (Microsoft) — Recomendada

Paquete que incluye múltiples extensiones útiles de una vez:

```bash
code --install-extension ms-vscode.cpptools-extension-pack
```

Incluye: C/C++, CMake Tools, y Themes para C/C++.

---

### 3. CMake Tools (Microsoft) — Para proyectos con CMake

Si usas CMake para construir tu proyecto SDL3 (recomendado):

```bash
code --install-extension ms-vscode.cmake-tools
```

Ofrece:
- Configuración y build de CMake desde la barra inferior de VS Code
- Selección de kit de compilación (GCC, Clang, etc.)
- Soporte para build/debug con un solo clic

---

### 4. CMake (twxs) — Resaltado de sintaxis para CMakeLists.txt

```bash
code --install-extension twxs.cmake
```

Añade coloreado y autocompletado en archivos `CMakeLists.txt`.

---

## Extensiones opcionales pero útiles

### clangd — IntelliSense alternativo (más rápido)

```bash
code --install-extension llvm-vs-code-extensions.vscode-clangd
```

> [!warning] Conflicto con ms-vscode.cpptools
> Si instalas `clangd`, desactiva el IntelliSense de `ms-vscode.cpptools` para evitar conflictos. En `settings.json` añade:
> ```json
> "C_Cpp.intelliSenseEngine": "disabled"
> ```

Para usar clangd necesitas instalarlo en el sistema:
```bash
sudo apt install clangd
```

### GitLens — Superpoderes para Git

```bash
code --install-extension eamodio.gitlens
```

### Error Lens — Errores inline en el código

```bash
code --install-extension usernamehw.errorlens
```

Muestra los errores del compilador directamente en la línea del código, sin tener que mirar el panel de Problems.

### Bracket Pair Colorizer (incluido en VS Code) — Colores en llaves

Ya viene integrado en VS Code moderno. Activar en settings:
```json
"editor.bracketPairColorization.enabled": true
```

---

## Instalar todas las esenciales de una vez

```bash
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cmake-tools
code --install-extension twxs.cmake
code --install-extension usernamehw.errorlens
```

---

## Verificar extensiones instaladas

```bash
code --list-extensions
```

Salida esperada (entre otras):
```
ms-vscode.cpptools
ms-vscode.cmake-tools
twxs.cmake
```

---

## Tabla resumen

| Extensión | ID | Uso |
|-----------|----|-----|
| C/C++ | `ms-vscode.cpptools` | IntelliSense, debug con GDB ✅ |
| CMake Tools | `ms-vscode.cmake-tools` | Build CMake integrado ✅ |
| CMake syntax | `twxs.cmake` | Coloreado CMakeLists.txt ✅ |
| clangd | `llvm-vs-code-extensions.vscode-clangd` | IntelliSense avanzado (opcional) |
| Error Lens | `usernamehw.errorlens` | Errores inline (recomendado) |
| GitLens | `eamodio.gitlens` | Git avanzado (opcional) |

---

> [!tip] Siguiente paso
> Con las extensiones instaladas, ahora hay que decirle a VS Code dónde está SDL3 para que IntelliSense pueda encontrar los headers. Ver [[16 - Configurar IntelliSense para SDL3]].

---

#vscode #extensiones #cpptools #cmake #intellisense #sdl3
