#include "ui/elements/container.hpp"
#include "core/render_context.hpp"

UIContainer::UIContainer(const UITransform &transform) : UIElement(transform) {}

// UIContainer::~UIContainer() = default;

UIElement &UIContainer::add(std::unique_ptr<UIElement> ele) {
  children_.push_back(std::move(ele));
  children_.back()->parent(this);
  return *children_.back().get();
}

void UIContainer::handleEvents(const Input &input, UIEventSink &sink) {
  if (!visible_)
    return;
  for (auto &el : children_) {
    if (el->visible()) {
      el->handleEvents(input, sink);
    }
  }
}

void UIContainer::render(const RenderContext &ctx) const {
  if (!visible_)
    return;

  UIElement::render(ctx);

  for (auto &el : children_) {
    if (el->visible()) {
      el->render(ctx);
    }
  }
}

void UIContainer::update(const UISpace &space, const float dt) {
  if (!visible_)
    return;

  UIElement::update(space, dt);

  for (auto &el : children_) {
    if (el->visible()) {
      el->update(space, dt);
    }
  }
}
