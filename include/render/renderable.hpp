#pragma once

#include "core/context/render.hpp"
#include "core/types.hpp"

class Renderable {
private:
public:
  virtual ~Renderable() = default;
  virtual void render(const RenderContext &renderCtx, const Float2 &pos,
                      const Float2 &size) const = 0;
};
