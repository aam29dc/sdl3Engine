#include "ui/style/solid.hpp"
#include "core/render_context.hpp"
#include "core/renderer.hpp"
/*
struct UIStyleParams {
  bool hovered = false;
  bool pressed = false;
  bool focused = false;
  bool visible = true;
};
*/
UISolidStyle::UISolidStyle(const SDL_Color &fill, const SDL_Color &outline) {
  outline_ = outline;

  fill_ = fill;

  hover_ = fill_;
  hover_.r = 0;

  pressed_ = fill_;
  pressed_.g = 0;

  focused_ = fill_;
  focused_.b = 0;
}

void UISolidStyle::render(const SDL_FRect &rect, const UIStyleParams &params,
                          const RenderContext &renderCtx) const {
  if (params.pressed) {
    renderCtx.renderer.setDrawColor(pressed_);
  } else if (params.hovered) {
    renderCtx.renderer.setDrawColor(hover_);
  } else if (params.focused) {
    renderCtx.renderer.setDrawColor(focused_);
  } else {
    renderCtx.renderer.setDrawColor(fill_);
  }
  renderCtx.renderer.drawFillRect(rect);

  renderCtx.renderer.setDrawColor(outline_);
  renderCtx.renderer.drawRect(rect);
}
