#include "managers/texture.hpp"
#include "core/handles.hpp"
#include "core/renderer.hpp"
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>

TextureHandle TextureManager::load(Renderer &renderer,
                                   const std::string &imgFile) {
  SDL_Texture *texture = IMG_LoadTexture(renderer.get(), imgFile.c_str());

  if (!texture) {
    std::cout << "Texture image: " << imgFile
              << " Failed to load: " << SDL_GetError() << std::endl;
    return {0};
  }
  u32 id = nextID_++;
  textures_[id] = texture;
  return {id};
}

TextureHandle TextureManager::load(SDL_Texture *texture) {
  if (!texture)
    return {0};
  u32 id = nextID_++;
  textures_[id] = texture;
  return {id};
}

bool TextureManager::remove(u32 id) {
  auto it = textures_.find(id);
  if (it == textures_.end())
    return false;

  SDL_DestroyTexture(it->second);
  textures_.erase(it);

  return true;
}

void TextureManager::clear() {
  for (auto &[id, texture] : textures_) {
    SDL_DestroyTexture(texture);
  }

  textures_.clear();
}

SDL_Texture *TextureManager::get(u32 id) const {
  auto it = textures_.find(id);
  if (it == textures_.end()) {
    return nullptr;
  }
  return it->second;
}
