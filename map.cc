#include "map.h"

#include "grid.h"
#include "position.h"

namespace cause_engine {
namespace map {

Map::Map(atlas::Atlas* atlas, Grid* grid) {
    atlas_ = atlas;
    grid_ = grid;

    tiles_ = new MapTile*[grid->GetGridSize()];
}

MapDraw Map::GetTilesToDraw() {
    MapDraw map_draw;

    map_draw.atlas = atlas_;
    map_draw.tiles_per_index = new int[atlas_->GetAtlasSize()];
    map_draw.tile_map_positions = new Position[num_tiles_];

    Position tilepos;

    for (int i = 0; i < grid_->GetGridSize(); i++) {
        MapTile* tile = tiles_[i];
        if (tile) {
            map_draw.tile_map_positions
                [map_draw.tiles_per_index[tile->tile_index]] =
                grid_->GridToMap(grid_->IndexToGrid(
                    i));  // Add position to positions array at point determined
                          // by number of identical textures
            map_draw
                .tiles_per_index[tile->tile_index]++;  // increment number of
                                                       // identical textures to
                                                       // keep it true
        }
    }

    return map_draw;
};

}  // namespace map
}  // namespace cause_engine
