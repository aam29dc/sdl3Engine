#pragma once
#include "core/handles.hpp"
#include "render/renderable.hpp"

class Sprite : public Renderable {
private:
  TextureHandle handle_;

public:
  void render(const RenderContext &renderCtx, const Float2 &pos,
              const Float2 &size) const;
};
