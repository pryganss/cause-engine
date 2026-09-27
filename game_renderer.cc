#include "game_renderer.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <string.h>

namespace cause_engine {
namespace renderer {

SDL_Window* game_window;
SDL_Renderer* game_renderer;

int SetupSDL() {
    // Setup SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return 1;
    }

    // Create 1000x800 window called Window with no flags
    game_window = SDL_CreateWindow("Window", 1000, 800, 0);

    if (!game_window) {
        SDL_Log("SDL_Window failed: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create Renderer and pass window
    game_renderer = SDL_CreateRenderer(game_window, nullptr);
    if (!game_renderer) {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        SDL_DestroyWindow(game_window);
        SDL_Quit();
        return 1;
    }

    return 0;
}

void DrawFrame() {
    if (!(SDL_SetRenderDrawColor(game_renderer, 0, 0, 0, 255) &&
          SDL_RenderClear(game_renderer) && SDL_RenderPresent(game_renderer)))
        SDL_Log("renderer::DrawFrame failed: %s", SDL_GetError());
}

}  // namespace renderer
}  // namespace cause_engine
