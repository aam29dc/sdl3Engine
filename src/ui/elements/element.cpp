#include "ui/elements/element.hpp"

UIElement::UIElement(const SDL_FRect &rect) : rect_(rect) {};

void UIElement::handleEvents(const Input &) {}
void UIElement::update(const float) {}
void UIElement::render(Renderer &renderer) const {
  renderer.setDrawColor(color_);
  renderer.drawFillRect(rect_);
  renderer.setDrawColor(outline_);
  renderer.drawRect(rect_);
}

i32 UIElement::id() const { return id_; }
const std::string &UIElement::name() const { return name_; }

bool UIElement::visible() const { return visible_; }
void UIElement::toggle() { visible_ = !visible_; }
