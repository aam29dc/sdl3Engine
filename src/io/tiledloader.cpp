#include "io/tiledloader.hpp"
#include "core/context/resource.hpp"
#include "resource/texturemanager.hpp"
#include "world/map.hpp"
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <sstream>
#include <stdexcept>

using json = nlohmann::json;

std::string TiledLoader::loadText(const std::string &path) {
  std::ifstream file(path);

  if (!file) {
    throw std::runtime_error("failed to open: " + path);
  }

  std::stringstream buffer;
  buffer << file.rdbuf();

  return buffer.str();
}

Map TiledLoader::load(const std::string &path, ResourceContext &resourceCtx) {
  Map map{};

  std::string jsonText = loadText(path);

  json j = json::parse(jsonText);

  map.width = j.at("width").get<int>();
  map.height = j.at("height").get<int>();
  map.tileWidth = j.at("tilewidth").get<int>();
  map.tileHeight = j.at("tileheight").get<int>();

  namespace fs = std::filesystem;

  fs::path mapDir = fs::path(path).parent_path();

  for (const auto &tsJson : j.at("tilesets")) {
    TileSet tileset{};

    tileset.firstGid = tsJson.at("firstgid").get<u32>();
    tileset.tileWidth = tsJson.at("tilewidth").get<int>();
    tileset.tileHeight = tsJson.at("tileheight").get<int>();
    tileset.tileCount = tsJson.at("tilecount").get<int>();
    tileset.columns = tsJson.at("columns").get<int>();

    fs::path imagePath = tsJson.at("image").get<std::string>();

    fs::path fullImagePath = mapDir / imagePath;

    tileset.handle = resourceCtx.textures.loadFromFile(
        resourceCtx.renderer, fullImagePath.lexically_normal().string());

    map.tileSets.push_back(std::move(tileset));
  }

  for (const auto &layerJson : j.at("layers")) {
    if (layerJson.at("type").get<std::string>() != "tilelayer")
      continue;

    TileLayer layer{};

    layer.name = layerJson.at("name").get<std::string>();
    layer.width = layerJson.at("width").get<int>();
    layer.height = layerJson.at("height").get<int>();

    layer.gids = layerJson.at("data").get<std::vector<u32>>();

    map.layers.push_back(std::move(layer));
  }

  for (const auto &layerJson : j.at("layers")) {
    if (layerJson.at("type").get<std::string>() != "objectgroup")
      continue;

    ObjectLayer layer{};
    layer.name = layerJson.at("name").get<std::string>();

    for (const auto &objJson : layerJson.at("objects")) {
      MapObject object{};

      object.id = objJson.at("id").get<int>();
      object.name = objJson.value("name", "");
      object.className = objJson.value("class", "");

      object.pos = {objJson.at("x").get<float>(), objJson.at("y").get<float>()};

      object.size = {objJson.value("width", 0.0f),
                     objJson.value("height", 0.0f)};

      // custom properties
      if (objJson.contains("properties")) {
        for (const auto &prop : objJson["properties"]) {
          std::string key = prop.at("name").get<std::string>();

          // simplest approach: store everything as strings
          std::string value;

          if (prop["value"].is_string())
            value = prop["value"].get<std::string>();
          else
            value = prop["value"].dump();

          object.props[key] = value;
        }
      }

      layer.objects.push_back(std::move(object));
    }

    map.objectLayers.push_back(std::move(layer));
  }

  return map;
}
