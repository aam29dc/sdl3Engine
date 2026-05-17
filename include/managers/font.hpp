#pragma once
#include "ui/colors.hpp"
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
class Renderer;
class FontManager {
public:
  enum class FontSize { Small, Medium, Large };
  static constexpr int TEXTSIZE_SMALL = 12;
  static constexpr int TEXTSIZE_MEDIUM = 17;
  static constexpr int TEXTSIZE_LARGE = 22;
  static constexpr int FONTWIDTH = 13;

private:
  SDL_Color color_{Color::Black};
  TTF_Font *small_{nullptr};
  TTF_Font *medium_{nullptr};
  TTF_Font *large_{nullptr};

public:
  FontManager() = default;
  ~FontManager();

  bool init(const std::string &fontPath);

  FontManager(const FontManager &) = delete;
  FontManager &operator=(const FontManager &) = delete;
  FontManager(FontManager &&) = delete;
  FontManager &operator=(FontManager &&) = delete;

  SDL_Texture *getText(Renderer *renderer, const std::string &text,
                       const FontSize size);
};
