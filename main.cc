#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>

#include "game_renderer.h"

int main() {
    if (cause_engine::renderer::SetupSDL() != 0) return 1;

    bool running = true;
    SDL_Event current_event;

    while (running) {
        while (SDL_PollEvent(&current_event)) {
            // User tries to close window
            if (current_event.type == SDL_EVENT_QUIT) running = false;

            // User presses any key
            if (current_event.type == SDL_EVENT_KEY_DOWN) running = false;
        }

        cause_engine::renderer::DrawFrame();
    }

    SDL_Quit();  // Quit SDL after project runs

    return 0;
}
