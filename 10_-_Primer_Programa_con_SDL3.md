# 10 - Primer Programa con SDL3

← [09_-_Configurar_el_Linker_para_SDL3]() | Siguiente → [[11_-_Compilar_un_Proyecto_con_SDL3]]

---

## Hola Mundo con SDL3 en C

Este programa crea una ventana SDL3 de color azul marino y espera a que el usuario la cierre.

### Crear el archivo

```bash
mkdir -p ~/mi-proyecto-sdl3
cd ~/mi-proyecto-sdl3
nano main.c
```

### Código fuente — `main.c`

```c
#include <SDL3/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    /* 1. Inicializar SDL3 — solo el subsistema de video */
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Error al iniciar SDL3: %s\n", SDL_GetError());
        return 1;
    }

    /* 2. Crear la ventana */
    SDL_Window *ventana = SDL_CreateWindow(
        "Hola SDL3 desde Debian",  /* título */
        800,                        /* ancho */
        600,                        /* alto */
        0                           /* flags */
    );

    if (!ventana) {
        fprintf(stderr, "Error al crear ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    /* 3. Crear el renderer */
    SDL_Renderer *renderer = SDL_CreateRenderer(ventana, NULL);
    if (!renderer) {
        fprintf(stderr, "Error al crear renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(ventana);
        SDL_Quit();
        return 1;
    }

    /* 4. Bucle principal */
    int corriendo = 1;
    SDL_Event evento;

    while (corriendo) {
        /* Procesar eventos */
        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_EVENT_QUIT) {
                corriendo = 0;
            }
            /* Salir también con ESC */
            if (evento.type == SDL_EVENT_KEY_DOWN &&
                evento.key.key == SDLK_ESCAPE) {
                corriendo = 0;
            }
        }

        /* Limpiar pantalla con color azul marino */
        SDL_SetRenderDrawColor(renderer, 15, 20, 50, 255);
        SDL_RenderClear(renderer);

        /* Dibujar un rectángulo blanco en el centro */
        SDL_FRect rect = { 300.0f, 225.0f, 200.0f, 150.0f };
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);

        /* Presentar el frame */
        SDL_RenderPresent(renderer);
    }

    /* 5. Limpiar recursos */
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    SDL_Quit();

    printf("¡SDL3 funciona correctamente!\n");
    return 0;
}
```

---

## Diferencias clave de SDL3 respecto a SDL2

| Característica | SDL2 | SDL3 |
|----------------|------|------|
| Inicialización | `SDL_Init()` retorna `int` | `SDL_Init()` retorna `bool` |
| Eventos | `SDL_QUIT` | `SDL_EVENT_QUIT` |
| Teclas | `SDL_KEYDOWN` | `SDL_EVENT_KEY_DOWN` |
| Rect para render | `SDL_Rect` (int) | `SDL_FRect` (float) |
| Renderer | `SDL_CreateRenderer(win, -1, 0)` | `SDL_CreateRenderer(win, NULL)` |

---

## Compilar el programa

Ve a [[11_-_Compilar_un_Proyecto_con_SDL3]] para ver cómo compilar este código con GCC o CMake.

---

> [!tip] Depuración
> Si la ventana no aparece o aparece en negro, asegúrate de que:
> 1. SDL3 está correctamente instalada (ver [[09_-_Configurar_el_Linker_para_SDL3]])
> 2. Tu sistema tiene un entorno gráfico funcionando (X11 o Wayland)
> 3. No hay errores de compilación o enlace

---

#sdl3 #c #holamundo #ventana #renderer #programa
