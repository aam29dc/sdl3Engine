#pragma once

#include "render/renderable.hpp"
#include <SDL3/SDL_pixels.h>

class Rect : public Renderable {
private:
  SDL_Color color_{255, 0, 0, 255};

public:
  void render(const RenderContext &renderCtx, const Float2 &pos,
              const Float2 &size) const;
};
