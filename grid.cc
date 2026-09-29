#include "grid.h"

#include <stdexcept>

#include "atlas.h"
#include "map.h"
#include "position.h"

namespace cause_engine {
namespace map {

Grid::Grid(int grid_size_x, int grid_size_y, int tile_size_x, int tile_size_y) {
    grid_size_x_ = grid_size_x;
    grid_size_y_ = grid_size_y;

    tile_size_x_ = tile_size_x;
    tile_size_y_ = tile_size_y;
}

Position Grid::GridToMap(Position grid_pos) {
    if (0 > grid_pos.x > grid_size_x_ - 1 || 0 > grid_pos.y > grid_size_y_ - 1)
        throw std::invalid_argument(
            "GridToMap: Position given is outside of grid bounds");
    Position map_pos;
    map_pos.x = grid_pos.x * tile_size_x_;
    map_pos.y = grid_pos.y * tile_size_y_;

    return map_pos;
}

Position Grid::MapToGrid(Position map_pos) {
    Position grid_pos;
    grid_pos.x = map_pos.x / tile_size_x_;
    grid_pos.y = map_pos.y / tile_size_y_;

    if (0 > grid_pos.x > grid_size_x_ - 1 || 0 > grid_pos.y > grid_size_y_ - 1)
        throw std::invalid_argument(
            "MapToGrid: Position given is outside of grid bounds");

    return grid_pos;
}

Position Grid::IndexToGrid(int index) {
    Position grid_pos;
    grid_pos.y = index / grid_size_x_;
    grid_pos.x = index % grid_size_x_;

    if (0 > grid_pos.x > grid_size_x_ - 1 || 0 > grid_pos.y > grid_size_y_ - 1)
        throw std::invalid_argument(
            "IndexToGrid: Position given is outside of grid bounds");

    return grid_pos;
}

int Grid::GetGridSize() { return grid_size_x_ * grid_size_y_; }

}  // namespace map
}  // namespace cause_engine
