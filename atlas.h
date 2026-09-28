#ifndef CAUSE_ATLAS_H_
#define CAUSE_ATLAS_H_

#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>

namespace cause_engine {
namespace atlas {

class Atlas {
   public:
    Atlas(SDL_Surface* surface, int t_width, int t_height, int margin_x,
          int margin_y);
    ~Atlas();
    SDL_Surface* GetSurfaceFromIndex(int index);

   private:
    SDL_Surface** srf_array;
    int array_len;
};

}  // namespace atlas
}  // namespace cause_engine

#endif
