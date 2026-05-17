#include "ui/elements/button.hpp"
#include "core/input.hpp"

UIButton::UIButton(const SDL_FRect &rect, const UICmd cmd)
    : UIElement(rect), cmd_(cmd) {}
// enum class MouseButton : u8 { Left = 0, Middle = 1, Right = 2, Count = 3 };

void UIButton::handleEvents(const Input &input) {
  const Int2 mpos = input.getMousePos();

  hovered_ = ((mpos.x >= rect_.x && mpos.x <= rect_.x + rect_.w) &&
              (mpos.y >= rect_.y && mpos.y <= rect_.y + rect_.h));

  pressed_ = (hovered_ && input.isMouseDown(Input::MouseButton::Left));
  clicked_ = (hovered_ && input.isMouseReleased(Input::MouseButton::Left));
}

void UIButton::update(const float) {
  if (clicked_ && cmd_ != UICmd::None) {
    clicked_ = false;
  }
}

void UIButton::render(Renderer &renderer) const {
  if (pressed_)
    renderer.setDrawColor(hover_);
  else if (hovered_)
    renderer.setDrawColor(click_);
  else
    renderer.setDrawColor(color_);

  renderer.drawFillRect(rect_);

  renderer.setDrawColor(outline_);
  renderer.drawRect(rect_);
}
