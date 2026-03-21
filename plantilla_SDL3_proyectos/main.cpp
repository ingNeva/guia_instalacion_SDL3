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
