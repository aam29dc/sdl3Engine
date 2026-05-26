#include "managers/font.hpp"
#include "core/renderer.hpp"
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>

bool FontManager::init(const std::string &fontPath) {
  fonts_[0] = TTF_OpenFont(fontPath.c_str(), TEXTSIZE_SMALL);
  fonts_[1] = TTF_OpenFont(fontPath.c_str(), TEXTSIZE_MEDIUM);
  fonts_[2] = TTF_OpenFont(fontPath.c_str(), TEXTSIZE_LARGE);

  if (!fonts_[0] || !fonts_[1] || !fonts_[2]) {
    std::cout << "TTF_OpenFont failed: " << SDL_GetError() << "\n";
    if (fonts_[0])
      TTF_CloseFont(fonts_[0]);
    if (fonts_[1])
      TTF_CloseFont(fonts_[1]);
    if (fonts_[2])
      TTF_CloseFont(fonts_[2]);
    fonts_[0] = fonts_[1] = fonts_[2] = nullptr;
    TTF_Quit();
    return false;
  }
  return true;
}

FontManager::~FontManager() {
  if (fonts_[0]) {
    TTF_CloseFont(fonts_[0]);
  }
  if (fonts_[1]) {
    TTF_CloseFont(fonts_[1]);
  }
  if (fonts_[2]) {
    TTF_CloseFont(fonts_[2]);
  }
}

SDL_Texture *FontManager::getText(Renderer *renderer, const std::string &text,
                                  const SDL_Color &color, const FontSize size,
                                  const float wrapWidth) const {
  if (text.empty()) {
    return nullptr;
  }

  TTF_Font *font = nullptr;
  switch (size) {
  case FontSize::Large:
    font = fonts_[2];
    break;
  case FontSize::Medium:
    font = fonts_[1];
    break;
  case FontSize::Small:
    font = fonts_[0];
    break;
  case FontSize::Count:
    break;
  }
  if (!font)
    return nullptr;

  SDL_Surface *surface = nullptr;

  if (wrapWidth > 0.0f) {
    surface = TTF_RenderText_Solid_Wrapped(font, text.c_str(), text.length(),
                                           color, wrapWidth);
  } else {
    surface = TTF_RenderText_Solid(font, text.c_str(), text.length(), color);
  }
  if (!surface) {
    std::cout << "Text surface error: " << SDL_GetError() << "\n";
    return nullptr;
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer->get(), surface);

  SDL_DestroySurface(surface);

  if (!texture) {
    std::cout << "SDL_CreateTextureFromSurface failed: " << SDL_GetError()
              << "\n";
    return nullptr;
  }

  return texture;
}
