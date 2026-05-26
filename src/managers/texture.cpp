#include "managers/texture.hpp"
#include "core/handles.hpp"
#include "core/renderer.hpp"
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>

TextureManager::~TextureManager() { clear(); }

TextureHandle TextureManager::loadFromFile(Renderer &renderer,
                                           const std::string &imgFile) {
  SDL_Texture *texture = IMG_LoadTexture(renderer.get(), imgFile.c_str());

  if (!texture) {
    std::cout << "Texture image: " << imgFile
              << " Failed to load: " << SDL_GetError() << std::endl;
    return {0};
  }

  u32 index = 0;

  if (!freeSlots_.empty()) {
    index = freeSlots_.back();
    freeSlots_.pop_back();
    textures_[index].generation++;
    textures_[index].texture = texture;
  } else {
    index = textures_.size();
    textures_.push_back({texture});
  }

  return {index, textures_[index].generation};
}

TextureHandle TextureManager::loadFromSurface(Renderer &, SDL_Surface *) {
  return {};
}

TextureHandle TextureManager::adopt(SDL_Texture *) { return {}; }

bool TextureManager::remove(TextureHandle handle) {
  if (textures_[handle.id].texture != nullptr) {
    SDL_DestroyTexture(textures_[handle.id].texture);
    textures_[handle.id].generation++;
    textures_[handle.id].texture = nullptr;
    freeSlots_.push_back(handle.id);
  }
  return true;
}

bool TextureManager::valid(TextureHandle handle) const {
  const auto &entry = textures_.at(handle.id);
  return entry.texture != nullptr && entry.generation == handle.generation;
}

void TextureManager::clear() {
  for (auto &[texture, id] : textures_) {
    SDL_DestroyTexture(texture);
  }

  textures_.clear();
}

const SDL_Texture *TextureManager::get(const TextureHandle handle) const {
  if (valid(handle)) {
    return textures_.at(handle.id).texture;
  }
  return nullptr;
}
