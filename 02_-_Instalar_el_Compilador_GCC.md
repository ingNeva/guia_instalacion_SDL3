# 02 - Instalar el Compilador GCC

← [[01 - Introducción y Requisitos]] | Siguiente → [[03 - Verificar la Instalación de GCC]]

---

## El paquete `build-essential`

La forma más sencilla de instalar GCC en Debian es mediante el metapaquete **`build-essential`**. Este paquete instala automáticamente:

| Paquete | Descripción |
|---------|-------------|
| `gcc` | Compilador C de GNU |
| `g++` | Compilador C++ de GNU |
| `make` | Herramienta de construcción |
| `dpkg-dev` | Herramientas de empaquetado Debian |
| `libc6-dev` | Headers de la librería C estándar |
| `linux-libc-dev` | Headers del kernel de Linux |

---

## Paso 1 — Actualizar la lista de paquetes

Siempre actualiza los índices de paquetes antes de instalar:

```bash
sudo apt update
```

Opcionalmente, actualiza también los paquetes existentes:

```bash
sudo apt upgrade -y
```

---

## Paso 2 — Instalar `build-essential`

```bash
sudo apt install build-essential -y
```

Este comando instala GCC y todas sus dependencias de compilación.

---

## Paso 3 — Instalar herramientas adicionales recomendadas

```bash
sudo apt install -y \
  manpages-dev \
  gdb \
  git \
  pkg-config \
  cmake \
  ninja-build
```

### ¿Para qué sirve cada una?

| Herramienta | Uso |
|-------------|-----|
| `manpages-dev` | Páginas de manual para desarrollo en C |
| `gdb` | Depurador GNU (indispensable para debug) |
| `git` | Control de versiones |
| `pkg-config` | Detectar flags de compilación de librerías |
| `cmake` | Sistema de build moderno (requerido por SDL3) |
| `ninja-build` | Backend de build rápido usado por CMake |

---

## Versiones de GCC por rama de Debian

| Debian | Codename | GCC por defecto |
|--------|----------|-----------------|
| Debian 11 | Bullseye | GCC 10.2 |
| Debian 12 | Bookworm | GCC 12.2 |
| Debian 13 | Trixie | GCC 14.2 |
| Debian 14 | Forky (testing) | GCC 15.x |

---

## Instalar una versión específica de GCC (opcional)

Si necesitas una versión concreta de GCC, puedes instalarla directamente:

```bash
# Instalar GCC 12 específicamente
sudo apt install gcc-12 g++-12

# Instalar GCC 14 (en trixie)
sudo apt install gcc-14 g++-14
```

### Configurar la versión predeterminada con `update-alternatives`

```bash
# Registrar GCC 12 y GCC 14 como alternativas
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 12
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-14 14

# Seleccionar cuál usar por defecto
sudo update-alternatives --config gcc
```

Se mostrará un menú interactivo para elegir la versión activa.

---

> [!note] Nota
> Para el desarrollo con SDL3, la versión de GCC que viene con `build-essential` es más que suficiente. No necesitas instalar versiones específicas salvo que lo requiera tu proyecto.

---

#gcc #build-essential #debian #instalacion #compilador
