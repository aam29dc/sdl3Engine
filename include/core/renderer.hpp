#pragma once
#include <SDL3/SDL_render.h>
class Window;

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

  void clear();
  void present();
  void setDrawColor(const SDL_Color &color);
  bool draw(SDL_Texture *texture, const SDL_FRect *src = nullptr,
            const SDL_FRect *dst = nullptr);

  void drawFillRect(const SDL_FRect &rect);
  void drawRect(const SDL_FRect &rect);
};
