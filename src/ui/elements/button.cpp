#include "ui/elements/button.hpp"
#include "core/input.hpp"
#include "ui/elements/container.hpp"
#include "ui/elements/element.hpp"
#include "ui/layout.hpp"

UIButton::UIButton(const UITransform &transform, const UICmd cmd)
    : UIElement(transform), cmd_(cmd) {}

void UIButton::handleEvents(const Input &input, UIEventSink &sink) {
  if (!visible_)
    return;
  const Int2 mpos = input.getMousePos();

  styleParams_.hovered = ((mpos.x >= resolvedRect_.x &&
                           mpos.x <= resolvedRect_.x + resolvedRect_.w) &&
                          (mpos.y >= resolvedRect_.y &&
                           mpos.y <= resolvedRect_.y + resolvedRect_.h));

  styleParams_.pressed =
      (styleParams_.hovered && input.isMouseDown(Input::MouseButton::Left));
  clicked_ =
      (styleParams_.hovered && input.isMouseReleased(Input::MouseButton::Left));

  if (clicked_ && cmd_ != UICmd::None) {
    sink.push({cmd_, id_});
  }
}

void UIButton::update(const UISpace &space, const float dt) {
  if (clicked_) {
    clicked_ = false;
  }
  UIElement::update(space, dt);
}
