#include "managers/font.hpp"
#include "core/renderer.hpp"
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>

bool FontManager::init(const std::string &fontPath) {
  if (!TTF_Init()) {
    std::cout << "TTF_Init failed: " << SDL_GetError() << "\n";
    return false;
  }
  small_ = TTF_OpenFont(fontPath.c_str(), TEXTSIZE_SMALL);
  medium_ = TTF_OpenFont(fontPath.c_str(), TEXTSIZE_MEDIUM);
  large_ = TTF_OpenFont(fontPath.c_str(), TEXTSIZE_LARGE);

  if (!small_ || !medium_ || !large_) {
    std::cout << "TTF_OpenFont failed: " << SDL_GetError() << "\n";
    if (small_)
      TTF_CloseFont(small_);
    if (medium_)
      TTF_CloseFont(medium_);
    if (large_)
      TTF_CloseFont(large_);
    small_ = medium_ = large_ = nullptr;
    TTF_Quit();
    return false;
  }
  return true;
}

FontManager::~FontManager() {
  if (small_) {
    TTF_CloseFont(small_);
  }
  if (medium_) {
    TTF_CloseFont(medium_);
  }
  if (large_) {
    TTF_CloseFont(large_);
  }
  small_ = medium_ = large_ = nullptr;
  TTF_Quit();
}

SDL_Texture *FontManager::getText(Renderer *renderer, const std::string &text,
                                  const FontSize size) {
  if (text.empty()) {
    return nullptr;
  }

  TTF_Font *font = nullptr;
  switch (size) {
  case FontSize::Large:
    font = large_;
    break;
  case FontSize::Medium:
    font = medium_;
    break;
  case FontSize::Small:
    font = small_;
    break;
  }
  if (!font)
    return nullptr;

  SDL_Surface *surface =
      TTF_RenderText_Solid(font, text.c_str(), text.length(), color_);
  if (!surface) {
    std::cout << "Text surface error: " << SDL_GetError() << "\n";
    return nullptr;
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer->get(), surface);
  if (!texture) {
    std::cout << "SDL_CreateTextureFromSurface failed: " << SDL_GetError()
              << "\n";
    SDL_DestroySurface(surface);
    return nullptr;
  }
  SDL_DestroySurface(surface);
  return texture;
}
