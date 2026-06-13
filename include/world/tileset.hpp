#pragma once
#include "core/handles.hpp"
#include "core/types.hpp"

struct TileSet { // image
  u32 firstGid = 1;

  int tileWidth = 0;
  int tileHeight = 0;

  int imageWidth = 0;
  int imageHeight = 0;

  int columns = 0;
  int tileCount = 0;

  TextureHandle handle;
};
