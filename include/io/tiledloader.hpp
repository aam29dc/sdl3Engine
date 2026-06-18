#pragma once

#include "world/map.hpp"
#include <string>

class ResourceContext;

class TiledLoader {
public:
  static Map load(const std::string &path, ResourceContext &resouceCtx);
  static std::string loadText(const std::string &path);
};
