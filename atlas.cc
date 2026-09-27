#include "atlas.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_surface.h>

#include <stdexcept>

namespace cause_engine {
namespace atlas {

Atlas::Atlas(SDL_Surface* surface, int t_width, int t_height) {
    if (surface->w < t_width || surface->h < t_height) {
        throw std::invalid_argument(
            "Surface too small to create Atlas from given dimensions");
    }

    array_len = (surface->w / t_width) * (surface->h / t_height);

    srf_array = new SDL_Surface*[array_len];

    int index = 0;

    SDL_Rect rect;
    rect.w = t_width;
    rect.h = t_height;

    rect.y = 0;
    while (rect.y <= surface->h - t_height) {
        rect.x = 0;
        while (rect.x <= surface->w - t_width) {
            SDL_Surface* new_surface =
                SDL_CreateSurface(t_width, t_height, surface->format);

            if (!SDL_BlitSurface(surface, &rect, new_surface, NULL)) {
                SDL_Log("Atlas: SDL_BlitSurface failed: %s", SDL_GetError());
            }

            srf_array[index] = SDL_DuplicateSurface(new_surface);

            SDL_DestroySurface(new_surface);

            index++;
            rect.x += t_width;
        }
        rect.y += t_height;
    }
}

Atlas::~Atlas() {
    for (int i = 0; i < array_len; i++) {
        SDL_DestroySurface(srf_array[i]);
    }
    delete[] srf_array;
}

SDL_Surface* Atlas::GetSurfaceFromIndex(int index) {
    if (0 > index >= array_len) {
        return NULL;
    }
    return srf_array[index];
}

}  // namespace atlas
}  // namespace cause_engine
