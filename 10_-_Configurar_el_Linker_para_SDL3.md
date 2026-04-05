# 07 - Configurar el Linker para SDL3

← [[09_-_Compilar_SDL3_desde_Fuente]] | Siguiente → [[11_-_Primer_Programa_con_SDL3]]

---

## ¿Por qué es necesario esto?

Cuando instalas SDL3 con el prefijo `/usr/local` (o cualquier directorio no estándar), el sistema no sabe automáticamente que existe esa librería. Necesitas decirle dónde buscar.

> [!note] Si instalaste en `/usr`
> Si seguiste la recomendación de `--prefix /usr`, **no necesitas hacer nada**. El sistema ya busca librerías en `/usr/lib`. Puedes saltar esta nota.

---

## Opción 1 — Actualizar el caché del linker (ldconfig)

Este es el método permanente y recomendado cuando instalas en `/usr/local`.

### Verificar que `/usr/local/lib` está en la lista

```bash
cat /etc/ld.so.conf.d/libc.conf
```

Si ves `/usr/local/lib` en la lista, solo ejecuta:

```bash
sudo ldconfig
```

### Si `/usr/local/lib` NO está en la lista

Crea un archivo de configuración:

```bash
echo "/usr/local/lib" | sudo tee /etc/ld.so.conf.d/sdl3.conf
sudo ldconfig
```

### Verificar que SDL3 fue registrada

```bash
ldconfig -p | grep SDL3
# libSDL3.so.0 (libc6,x86-64) => /usr/local/lib/libSDL3.so.0
# libSDL3.so (libc6,x86-64) => /usr/local/lib/libSDL3.so
```

---

## Opción 2 — Variable de entorno `LD_LIBRARY_PATH`

Útil para pruebas temporales o sin permisos sudo:

```bash
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
```

Para hacerlo permanente, añádelo a tu `~/.bashrc` o `~/.profile`:

```bash
echo 'export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH' >> ~/.bashrc
source ~/.bashrc
```

> [!warning] Limitación
> `LD_LIBRARY_PATH` afecta solo a tu usuario y solo cuando está definida en la sesión. No es la solución más limpia para un sistema de desarrollo permanente.

---

## Verificar que SDL3 es encontrable por `pkg-config`

```bash
pkg-config --modversion sdl3
```

Si `pkg-config` no encuentra SDL3 instalada en `/usr/local`:

```bash
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH
pkg-config --modversion sdl3
# 3.2.20
```

Para hacerlo permanente:

```bash
echo 'export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH' >> ~/.bashrc
source ~/.bashrc
```

---

## Verificación final

Después de configurar el linker, verifica que todo funciona:

```bash
# El linker encuentra SDL3
ldconfig -p | grep SDL3

# pkg-config devuelve la versión
pkg-config --modversion sdl3

# Los flags son correctos
pkg-config --cflags --libs sdl3
# -I/usr/local/include/SDL3 -L/usr/local/lib -lSDL3
```

Si todo responde correctamente, estás listo para [[11_-_Primer_Programa_con_SDL3]].

---

#sdl3 #linker #ldconfig #pkgconfig #debian #libreria
