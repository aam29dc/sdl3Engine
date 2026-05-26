#pragma once
#include "ui/style/style.hpp"
#include <SDL3/SDL_pixels.h>

class UISolidStyle : public UIStyle {
private:
  SDL_Color fill_{225, 225, 225, 255};
  SDL_Color hover_ = {0, fill_.g, fill_.b, fill_.a};
  SDL_Color pressed_ = {fill_.r, 0, fill_.b, fill_.a};
  SDL_Color focused_ = {fill_.r, fill_.g, 0, fill_.a};
  SDL_Color outline_ = {0, 0, 0, 255};

public:
  UISolidStyle(const SDL_Color &fill = {225, 225, 255, 255},
               const SDL_Color &outline = {0, 0, 0, 255});

  void render(const SDL_FRect &rect, const UIStyleParams &params,
              const RenderContext &renderCtx) const override;
};
