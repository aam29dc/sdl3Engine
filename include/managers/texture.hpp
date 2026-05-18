#pragma once
#include "core/handles.hpp"
#include "core/types.hpp"

class SDL_Texture;
class Renderer;
#include <string>
#include <unordered_map>

class TextureManager {
private:
  std::unordered_map<u32, SDL_Texture *> textures_;
  u32 nextID_ = 1;

public:
  TextureManager() = default;
  ~TextureManager() = default;

  TextureManager(const TextureManager &) = delete;
  TextureManager &operator=(const TextureManager &) = delete;
  TextureManager(TextureManager &&) = delete;
  TextureManager &operator=(TextureManager &&) = delete;

  TextureHandle load(Renderer &renderer, const std::string &imgFile);
  TextureHandle load(SDL_Texture *texture);

  bool remove(u32 id);
  void clear();
  SDL_Texture *get(u32 id) const;
};
