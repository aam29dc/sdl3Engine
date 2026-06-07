#include "ui/style/solid.hpp"
#include "core/context/render.hpp"
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

  const SDL_Color *fill = &fill_;

  if (params.pressed) {
    fill = &pressed_;
  } else if (params.hovered) {
    fill = &hover_;
  } else if (params.focused) {
    fill = &focused_;
  }
  renderCtx.renderer.setDrawColor(*fill);
  renderCtx.renderer.drawFillRect(rect);

  renderCtx.renderer.setDrawColor(outline_);
  renderCtx.renderer.drawRect(rect);
}
