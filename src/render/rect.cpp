#include "render/rect.hpp"
#include "core/renderer.hpp"

void Rect::render(const RenderContext &renderCtx, const Float2 &pos,
                  const Float2 &size) const {
  renderCtx.renderer.setDrawColor(color_);
  SDL_FRect rect = {pos.x, pos.y, size.x, size.y};
  renderCtx.renderer.drawFillRect(rect);
}
