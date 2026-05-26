#include "ui/elements/button.hpp"
#include "core/input.hpp"
#include "ui/elements/container.hpp"
#include "ui/layout.hpp"

UIButton::UIButton(const UITransform &transform, const UICmd cmd)
    : UIElement(transform), cmd_(cmd) {}

void UIButton::handleEvents(const Input &input, const UISpace &space,
                            UIEventSink &sink) {
  if (!visible_)
    return;
  const Int2 mpos = input.getMousePos();
  const SDL_FRect rect = resolveRect(transform_, space);

  styleParams_.hovered = ((mpos.x >= rect.x && mpos.x <= rect.x + rect.w) &&
                          (mpos.y >= rect.y && mpos.y <= rect.y + rect.h));

  styleParams_.pressed =
      (styleParams_.hovered && input.isMouseDown(Input::MouseButton::Left));
  clicked_ =
      (styleParams_.hovered && input.isMouseReleased(Input::MouseButton::Left));

  if (clicked_ && cmd_ != UICmd::None) {
    sink.push({cmd_, id_});
  }
}

void UIButton::update(const float) {
  if (clicked_) {
    clicked_ = false;
  }
  if (!visible_)
    return;
}
