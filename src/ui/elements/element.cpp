#include "ui/elements/element.hpp"
#include "core/render_context.hpp"
#include "ui/content/content.hpp"
#include "ui/layout.hpp"
#include "ui/style/solid.hpp"

UIElement::UIElement(const UITransform &transform) : transform_(transform) {
  style_ = std::make_unique<UISolidStyle>();
};

UIElement::~UIElement() = default;

void UIElement::handleEvents(const Input &, const UISpace &, UIEventSink &) {
  if (!visible_)
    return;
}

void UIElement::update(const float) {
  if (!visible_)
    return;
}

void UIElement::render(const RenderContext &ctx) const {
  if (!visible_)
    return;

  SDL_FRect rect = resolveRect(transform_, ctx.uiSpace);

  if (style_) {
    style_->render(rect, styleParams_, ctx);
  }

  for (const auto &c : contents_) {
    c->render(rect, ctx);
  }
}

UITransform &UIElement::transform() { return transform_; }
i32 UIElement::id() const { return id_; }
bool UIElement::visible() const { return visible_; }
void UIElement::visible(bool value) { visible_ = value; }
