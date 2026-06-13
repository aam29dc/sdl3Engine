#pragma once
#include "core/types.hpp"
#include <string>
#include <vector>

struct TileLayer { // array of tiles
  std::string name;
  int width = 0;  // tiles across
  int height = 0; // tiles down

  std::vector<u32> gids;
};
