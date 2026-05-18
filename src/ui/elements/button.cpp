#include "ui/elements/button.hpp"
#include "core/input.hpp"
#include "core/render_context.hpp"
#include "core/renderer.hpp"

UIButton::UIButton(const SDL_FRect &rect, const UICmd cmd)
    : UIElement(rect), cmd_(cmd) {}
// enum class MouseButton : u8 { Left = 0, Middle = 1, Right = 2, Count = 3 };

void UIButton::handleEvents(const Input &input) {
  const Int2 mpos = input.getMousePos();

  hovered_ = ((mpos.x >= rect_.x && mpos.x <= rect_.x + rect_.w) &&
              (mpos.y >= rect_.y && mpos.y <= rect_.y + rect_.h));

  pressed_ = (hovered_ && input.isMouseDown(Input::MouseButton::Left));
  clicked_ = (hovered_ && input.isMouseReleased(Input::MouseButton::Left));

  UIElement::handleEvents(input);
}

void UIButton::update(const float dt) {
  if (clicked_ && cmd_ != UICmd::None) {
    clicked_ = false;
  }

  UIElement::update(dt);
}

void UIButton::render(const RenderContext &ctx) const {
  if (pressed_)
    ctx.renderer.setDrawColor(hover_);
  else if (hovered_)
    ctx.renderer.setDrawColor(click_);
  else
    ctx.renderer.setDrawColor(color_);

  ctx.renderer.drawFillRect(rect_);
  ctx.renderer.setDrawColor(outline_);
  ctx.renderer.drawRect(rect_);

  UIElement::render(ctx);
}
