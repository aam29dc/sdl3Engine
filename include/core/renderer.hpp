#pragma once
// #include "core/handles.hpp"
#include <SDL3/SDL_render.h>
class Window;
// class TextureManager;
class Renderer {
private:
  SDL_Renderer *renderer_ = nullptr;

public:
  Renderer() = default;
  ~Renderer();

  SDL_Renderer *get();

  Renderer(const Renderer &) = delete;
  Renderer &operator=(const Renderer &) = delete;
  Renderer(Renderer &&) = delete;
  Renderer &operator=(Renderer &&) = delete;

  bool init(Window *window);

  void clear() const;
  void present() const;
  void setDrawColor(const SDL_Color &color) const;
  void draw(SDL_Texture *texture, const SDL_FRect *src = nullptr,
            const SDL_FRect *dst = nullptr) const;
  /*  void draw(const TextureManager &textures, const TextureHandle handle,
              const SDL_FRect *src = nullptr, const SDL_FRect *dst = nullptr);*/

  void drawFillRect(const SDL_FRect &rect) const;
  void drawRect(const SDL_FRect &rect) const;
};
