#ifndef CAUSE_GRID_H_
#define CAUSE_GRID_H_

#include "position.h"

namespace cause_engine {
namespace map {

class Grid {
   public:
    Grid(int grid_size_x, int grid_size_y, int tile_size_x, int tile_size_y);
    Position GridToMap(Position grid_pos);
    Position MapToGrid(Position map_pos);
    Position IndexToGrid(int index);
    int GetGridSize();

   private:
    int grid_size_x_;
    int grid_size_y_;
    int tile_size_x_;
    int tile_size_y_;
};

}  // namespace map
}  // namespace cause_engine

#endif
