#pragma once

#include "world/entitymanager.hpp"
#include "world/map.hpp"

struct World {
  Map map;
  EntityManager entities;
};
