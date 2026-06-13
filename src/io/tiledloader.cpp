#include "io/tiledloader.hpp"
#include "core/context/resource.hpp"
#include "io/jsonloader.hpp"
#include "resource/texturemanager.hpp"
#include <filesystem>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Map TiledLoader::load(const std::string &path, ResourceContext &resourceCtx) {
  Map map{};

  std::string jsonText = JsonLoader::loadText(path);

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

  return map;
}
