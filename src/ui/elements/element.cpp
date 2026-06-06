#include "ui/elements/element.hpp"
#include "core/context/render.hpp"
#include "ui/content/content.hpp"
#include "ui/layout.hpp"
#include "ui/style/solid.hpp"

UIElement::UIElement(const UITransform &transform) : transform_(transform) {
  style_ = std::make_unique<UISolidStyle>();
};

UIElement::~UIElement() = default;

void UIElement::handleEvents(const Input &, UIEventSink &) {
  if (!visible_)
    return;
}

void UIElement::update(const UISpace &space, const float) {
  if (!visible_)
    return;
  if (any(dirty_)) {
    resolvedRect_ = resolveRect(transform_, space);
  }
}

void UIElement::render(const RenderContext &ctx) const {
  if (!visible_)
    return;

  if (style_) {
    style_->render(resolvedRect_, styleParams_, ctx);
  }

  for (const auto &c : contents_) {
    c->render(resolvedRect_, ctx);
  }
}

void UIElement::markDirty(const Dirty d) {
  if (d != Dirty::None) {
    dirty_ |= d;
  }
}

void UIElement::style(std::unique_ptr<UIStyle> style) {
  if (style) {
    style_ = std::move(style);
    markDirty(Dirty::Render);
  }
}

void UIElement::addContent(std::unique_ptr<UIContent> content) {
  if (content) {
    contents_.push_back(std::move(content));
    markDirty(Dirty::Render);
  }
}

void UIElement::parent(UIContainer *root) { parent_ = root; }

UITransform &UIElement::transform() { return transform_; }

i32 UIElement::id() const { return id_; }

bool UIElement::visible() const { return visible_; }

void UIElement::visible(bool value) { visible_ = value; }
