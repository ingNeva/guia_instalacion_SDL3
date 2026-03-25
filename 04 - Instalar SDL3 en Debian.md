# 04 - Instalar SDL3 en Debian

← [[03 - Verificar la Instalación de GCC]] | Siguiente → [[05 - Dependencias de SDL3]]

---

## Situación de SDL3 en los repositorios de Debian

| Debian | Codename | SDL3 en apt | Versión disponible |
|--------|----------|-------------|-------------------|
| Debian 12 | Bookworm | ❌ No | — |
| Debian 13 | Trixie | ✅ Sí | 3.2.10 |
| Debian 14 | Forky (testing) | ✅ Sí | 3.2.20+ |

> [!info] Estado actual (Marzo 2026)
> Debian 13 Trixie es la versión **estable** actual desde Octubre 2025. `libsdl3-dev` está disponible en sus repositorios oficiales.

---

## Ruta A — Debian 13 Trixie o superior (recomendado)

Si tienes Debian 13 (Trixie) o Debian 14 (Forky), puedes instalar SDL3 directamente:

```bash
sudo apt update
sudo apt install libsdl3-dev
```

Esto instalará automáticamente:
- `libsdl3-3` — la librería dinámica
- `libsdl3-dev` — los headers y archivos de desarrollo

### Verificar la instalación

```bash
dpkg -l libsdl3-dev
# ii  libsdl3-dev   3.2.10+ds-1   ...
```

### Paquetes adicionales opcionales para SDL3

```bash
# Carga de imágenes (PNG, JPG, etc.)
sudo apt install libsdl3-image-dev

# Fuentes TrueType
sudo apt install libsdl3-ttf-dev
```

---

## Ruta B — Debian 12 Bookworm (compilar desde fuente)

En Bookworm, SDL3 **no está en los repositorios**. Debes compilarla manualmente.

El proceso es:

1. Instalar las dependencias → [[05 - Dependencias de SDL3]]
2. Descargar el código fuente de SDL3
3. Compilar con CMake
4. Instalar y registrar la librería

→ Guía completa: [[06 - Compilar SDL3 desde Fuente]]

---

## ¿Cómo sé qué versión de Debian tengo?

```bash
cat /etc/debian_version
# 13.1 → Trixie
# 12.x → Bookworm

lsb_release -a
# Distributor ID: Debian
# Description:    Debian GNU/Linux 13 (trixie)
```

---

> [!tip] Recomendación
> Si estás en Bookworm y puedes actualizar a Trixie, considera hacerlo. La actualización simplifica enormemente la instalación de SDL3 y te da GCC 14 y otras mejoras. Consulta la [[10 - Errores Comunes y Soluciones]] si tienes dudas.

---

#sdl3 #debian #apt #instalacion #trixie #bookworm
