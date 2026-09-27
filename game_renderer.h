#ifndef CAUSE_GAME_RENDERER_H_
#define CAUSE_GAME_RENDERER_H_
#include <SDL3/SDL.h>

namespace cause_engine {
namespace renderer {

extern SDL_Window* game_window;
extern SDL_Renderer* game_renderer;

int SetupSDL();
void DrawFrame();

}  // namespace renderer
}  // namespace cause_engine

#endif
