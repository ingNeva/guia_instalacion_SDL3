# 11 - Instalar Visual Studio Code en Debian

← [[00 - Índice Principal]] | Siguiente → [[15 - Extensiones para C y SDL3 en VS Code]]

---

## ¿Qué es VS Code?

**Visual Studio Code** (VS Code) es un editor de código fuente gratuito y de código abierto desarrollado por Microsoft. Aunque el nombre suena similar a "Visual Studio" (el IDE completo de Microsoft), son productos distintos: VS Code es ligero, extensible y funciona perfectamente en Linux.

> [!note] VS Code vs Visual Studio
> **VS Code** → editor ligero, multiplataforma, gratuito, ideal para C/SDL3 en Linux
> **Visual Studio** → IDE pesado de Microsoft, solo Windows/Mac, orientado a .NET y C++/Windows

---

## Método 1 — Repositorio oficial de Microsoft (recomendado)

Este método configura actualizaciones automáticas a través de `apt`.

### Paso 1 — Instalar dependencias previas

```bash
sudo apt update
sudo apt install -y wget gpg apt-transport-https
```

### Paso 2 — Importar la clave GPG de Microsoft

```bash
wget -qO- https://packages.microsoft.com/keys/microsoft.asc \
  | gpg --dearmor > packages.microsoft.gpg

sudo install -D -o root -g root -m 644 \
  packages.microsoft.gpg \
  /usr/share/keyrings/packages.microsoft.gpg

rm packages.microsoft.gpg
```

### Paso 3 — Agregar el repositorio de VS Code

```bash
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf \
  signed-by=/usr/share/keyrings/packages.microsoft.gpg] \
  https://packages.microsoft.com/repos/code stable main" \
  > /etc/apt/sources.list.d/vscode.list'
```

### Paso 4 — Instalar VS Code

```bash
sudo apt update
sudo apt install code
```

### Paso 5 — Verificar la instalación

```bash
code --version
# 1.xx.x
# xxxxxxxxxxxxxxxx
# x64
```

---

## Método 2 — Descargar el .deb directamente

Si prefieres no agregar el repositorio de Microsoft:

```bash
# Descargar el paquete .deb más reciente
wget -O /tmp/vscode.deb \
  "https://code.visualstudio.com/sha/download?build=stable&os=linux-deb-x64"

# Instalar
sudo apt install /tmp/vscode.deb

# Limpiar
rm /tmp/vscode.deb
```

> [!warning] Sin actualizaciones automáticas
> Con este método, VS Code **no se actualizará automáticamente** con `apt upgrade`. Tendrás que descargar e instalar nuevas versiones manualmente, o repetir el proceso.

---

## Método 3 — Flatpak (alternativa sin root)

```bash
# Instalar Flatpak si no lo tienes
sudo apt install flatpak

# Agregar Flathub
flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo

# Instalar VS Code
flatpak install flathub com.visualstudio.code

# Ejecutar
flatpak run com.visualstudio.code
```

> [!warning] Limitación importante del Flatpak
> VS Code instalado como Flatpak corre en un **sandbox** y **no puede acceder a SDKs del sistema** (como GCC o SDL3). Para desarrollo en C con SDL3, usa el Método 1 o 2.

---

## Lanzar VS Code

### Desde el terminal (recomendado)

```bash
# Abrir VS Code en el directorio actual
code .

# Abrir un archivo específico
code main.c

# Abrir una carpeta de proyecto
code ~/mi-proyecto-sdl3
```

### Configurar VS Code como editor predeterminado del sistema

```bash
sudo update-alternatives --set editor /usr/bin/code
```

---

## Actualizar VS Code

Si instalaste con el Método 1 (repositorio Microsoft):

```bash
sudo apt update && sudo apt upgrade code
```

---

## Desinstalar VS Code

```bash
# Desinstalar el paquete
sudo apt remove code

# Eliminar también el repositorio (opcional)
sudo rm /etc/apt/sources.list.d/vscode.list
sudo rm /usr/share/keyrings/packages.microsoft.gpg
```

Para eliminar también la configuración del usuario:
```bash
rm -rf ~/.config/Code
rm -rf ~/.vscode
```

---

#vscode #debian #instalacion #editor #microsoft
