#include "core/types.hpp"
#include <string>
#include <unordered_map>
#include <vector>

struct MapObject {
  int id = 0;
  std::string name;
  std::string className;

  Float2 pos;
  Float2 size;

  std::unordered_map<std::string, std::string> props;
};

struct ObjectLayer {
  std::string name;
  std::vector<MapObject> objects;
};
