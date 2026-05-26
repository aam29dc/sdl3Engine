#pragma once

#include "core/handles.hpp"
#include "core/types.hpp"
#include <string>
#include <vector>

class Renderer;
class SDL_Texture;
class SDL_Surface;

class TextureManager {
private:
  struct Entry {
    SDL_Texture *texture = nullptr;
    u32 generation = 1;
  };

  std::vector<Entry> textures_;
  std::vector<u32> freeSlots_;

public:
  ~TextureManager();
  TextureHandle loadFromFile(Renderer &, const std::string &);
  TextureHandle loadFromSurface(Renderer &, SDL_Surface *);
  TextureHandle adopt(SDL_Texture *);

  bool remove(TextureHandle handle);
  bool valid(TextureHandle handle) const;

  const SDL_Texture *get(const TextureHandle handle) const;

  void clear();
};
