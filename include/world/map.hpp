#pragma once
#include "world/mapobject.hpp"
#include "world/tilelayer.hpp"
#include "world/tileset.hpp"

struct Map { // array of tilesets, and layers
  int width = 0;
  int height = 0;

  int tileWidth = 0;
  int tileHeight = 0;

  std::vector<TileSet> tileSets;
  std::vector<TileLayer> layers;
  std::vector<ObjectLayer> objectLayers;
};
