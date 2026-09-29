#ifndef CAUSE_MAP_H_
#define CAUSE_MAP_H_

#include <string>

#include "atlas.h"
#include "grid.h"
#include "position.h"

namespace cause_engine {
namespace map {

struct MapTile {
    int tile_index;
};

struct MapDraw {
    atlas::Atlas* atlas;
    int* tiles_per_index;
    Position* tile_map_positions;
};

class Map {
   public:
    Map(atlas::Atlas* atlas, Grid* grid);
    int LoadMapFromFile(std::string path);
    MapDraw GetTilesToDraw();
    void AddTile(MapTile tile, Position pos);

   private:
    Grid* grid_;
    atlas::Atlas* atlas_;
    MapTile** tiles_;
    int num_tiles_;
};

}  // namespace map
}  // namespace cause_engine

#endif  // CAUSE_MAP_H_
