#pragma once

#include <SDL3/SDL_pixels.h>
#include <array>
#include <string>

struct TTF_Font;
class Renderer;
class TextureManager;
struct SDL_Texture;

class FontManager {
public:
  enum class FontSize : std::size_t { Small = 0, Medium, Large, Count };

  static constexpr int TEXTSIZE_SMALL = 12;
  static constexpr int TEXTSIZE_MEDIUM = 17;
  static constexpr int TEXTSIZE_LARGE = 22;

private:
  std::array<TTF_Font *, static_cast<std::size_t>(FontSize::Count)> fonts_{};

public:
  FontManager() = default;
  ~FontManager();

  FontManager(const FontManager &) = delete;
  FontManager &operator=(const FontManager &) = delete;
  FontManager(FontManager &&) = delete;
  FontManager &operator=(FontManager &&) = delete;

  bool init(const std::string &fontPath);

  // raw surface only if explicitly needed (debug / legacy path)
  /*  SDL_Surface *renderTextSurface(const std::string &text, FontSize size,
                                   SDL_Color color, float wrapWidth = 0.0f)
     const;*/

  SDL_Texture *getText(Renderer *renderer, const std::string &text,
                       const SDL_Color &color, const FontSize size,
                       const float wrapWidth) const;

  TTF_Font *get(FontSize size) const;
};
