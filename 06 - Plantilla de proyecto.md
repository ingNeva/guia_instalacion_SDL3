# 06 - Plantilla de proyecto

tags: #sdl3 #plantilla #proyecto #cpp

---

## Estructura de un proyecto nuevo

Cada proyecto nuevo necesita esta estructura:

```
nombre_proyecto/
├── .vscode/
│   ├── tasks.json           ← copiar de [[05 - Configurar VS Code]]
│   └── c_cpp_properties.json ← copiar de [[05 - Configurar VS Code]]
├── SDL3.dll
├── SDL3_image.dll
├── SDL3_ttf.dll
├── SDL3_mixer.dll
├── SDL3_net.dll
└── main.cpp
```

---

## DLLs necesarias

Copia estos archivos desde `C:\msys64\ucrt64\bin\` a la carpeta raiz de cada proyecto:

```
SDL3.dll
SDL3_image.dll
SDL3_ttf.dll
SDL3_mixer.dll
SDL3_net.dll
```

> [!info]
> Sin estos archivos el `.exe` compilado no puede ejecutarse fuera de la terminal MSYS2, ya que Windows no sabe donde encontrar las librerias.

---

## main.cpp de prueba (ventana minima)

```cpp
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* win = SDL_CreateWindow("SDL3 OK", 800, 600, 0);
    SDL_Renderer* ren = SDL_CreateRenderer(win, NULL);

    SDL_SetRenderDrawColor(ren, 20, 60, 120, 255);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
    SDL_Delay(2000);

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
```

Resultado esperado: ventana azul oscuro de 800x600 que se cierra sola a los 2 segundos.

---

## main.cpp con bucle de eventos (base real)

```cpp
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* win = SDL_CreateWindow("Mi Juego", 800, 600, 0);
    SDL_Renderer* ren = SDL_CreateRenderer(win, NULL);

    bool corriendo = true;
    SDL_Event evento;

    while (corriendo) {
        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_EVENT_QUIT) {
                corriendo = false;
            }
            if (evento.type == SDL_EVENT_KEY_DOWN) {
                if (evento.key.key == SDLK_ESCAPE) {
                    corriendo = false;
                }
            }
        }

        SDL_SetRenderDrawColor(ren, 20, 60, 120, 255);
        SDL_RenderClear(ren);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
```

Esta version mantiene la ventana abierta hasta que se cierra con la X o se presiona `Escape`.

---

## Headers disponibles por libreria

| Libreria | Include |
|---|---|
| SDL3 base | `#include <SDL3/SDL.h>` |
| SDL3_image | `#include <SDL3/SDL_image.h>` |
| SDL3_ttf | `#include <SDL3/SDL_ttf.h>` |
| SDL3_mixer | `#include <SDL3/SDL_mixer.h>` |
| SDL3_net | `#include <SDL3_net/SDL_net.h>` |

---

## Referencias

- [[README]]
- [[05 - Configurar VS Code]]
- [[07 - Errores comunes y soluciones]]
