#pragma once
#include <SDL3/SDL_rect.h>

struct UIStyleParams {
  bool hovered = false;
  bool pressed = false;
  bool focused = false;
};

struct RenderContext;

class UIStyle {
public:
  virtual ~UIStyle() = default;

  virtual void render(const SDL_FRect &rect, const UIStyleParams &params,
                      const RenderContext &renderCtx) const = 0;
};
