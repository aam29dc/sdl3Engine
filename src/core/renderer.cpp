#include "core/renderer.hpp"
#include "core/window.hpp"
// #include "managers/texture.hpp"
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>

Renderer::~Renderer() {
  if (renderer_) {
    SDL_DestroyRenderer(renderer_);
  }
  renderer_ = nullptr;
}

bool Renderer::init(Window *window) {
  if (!window) {
    return false;
  }
  renderer_ = SDL_CreateRenderer(window->get(), "opengl");
  if (!renderer_) {
    SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
    return false;
  }
  return true;
}

void Renderer::clear() const { SDL_RenderClear(renderer_); }
void Renderer::present() const { SDL_RenderPresent(renderer_); }

void Renderer::setDrawColor(const SDL_Color &color) const {
  SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
}
void Renderer::drawFillRect(const SDL_FRect &rect) const {
  SDL_RenderFillRect(renderer_, &rect);
}

void Renderer::drawRect(const SDL_FRect &rect) const {
  SDL_RenderRect(renderer_, &rect);
}

void Renderer::draw(SDL_Texture *texture, const SDL_FRect *src,
                    const SDL_FRect *dst) const {
  SDL_RenderTexture(renderer_, texture, src, dst);
}
SDL_Renderer *Renderer::get() { return renderer_; }
