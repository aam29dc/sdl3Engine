#include "ui/elements/element.hpp"
#include "core/render_context.hpp"

UIElement::UIElement(const SDL_FRect &rect) : rect_(rect) {};

void UIElement::handleEvents(const Input &input) {
  for (auto &el : children_) {
    el->handleEvents(input);
  }
}
void UIElement::update(const float dt) {
  for (auto &el : children_) {
    el->update(dt);
  }
}
void UIElement::render(const RenderContext &ctx) const {
  /*  renderer.setDrawColor(color_);
    renderer.drawFillRect(rect_);
    renderer.setDrawColor(outline_);
    renderer.drawRect(rect_);
   */
  for (auto &el : children_) {
    el->render(ctx);
  }
}

void UIElement::add(std::unique_ptr<UIElement> ele) {
  children_.push_back(std::move(ele));
}

i32 UIElement::id() const { return id_; }
const std::string &UIElement::name() const { return name_; }

bool UIElement::visible() const { return visible_; }
void UIElement::toggle() { visible_ = !visible_; }
