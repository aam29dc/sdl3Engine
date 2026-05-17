#include "ui/elements/container.hpp"
#include "ui/elements/button.hpp"

UIContainer::UIContainer() = default;
UIContainer::~UIContainer() = default;

void UIContainer::add(std::unique_ptr<UIElement> ele) {
  eles_.push_back(std::move(ele));
}

std::queue<UICmd> UIContainer::handleEvents(const Input &input) {
  std::queue<UICmd> cmds;
  for (auto &el : eles_) {
    if (el->visible()) {
      el->handleEvents(input);
      UIButton *but = dynamic_cast<UIButton *>(el.get());
      if (but) {
        if (but->clicked()) {
          cmds.push(but->cmd());
        }
      }
    }
  }
  return cmds;
}

void UIContainer::render(Renderer &renderer) const {
  for (auto &el : eles_) {
    if (el->visible()) {
      el->render(renderer);
    }
  }
}
void UIContainer::update(const float dt) {
  for (auto &el : eles_) {
    if (el->visible()) {
      el->update(dt);
    }
  }
}
