#include "ui/content/text.hpp"
#include "core/context/render.hpp"
#include "core/context/resource.hpp"
#include "core/renderer.hpp"
#include "managers/font.hpp"
#include "managers/texture.hpp"

UITextContent::UITextContent(UIElement *owner, const std::string &text,
                             const FontManager::FontSize size)
    : text_(text), size_(size) {
  owner_ = owner;
  if (owner_)
    owner_->markDirty(Dirty::Layout);
}

// rect same size as style rect thus overwrites, we should decrease the size by
// 2px on x and y, and recenter
void UITextContent::render(const SDL_FRect &rect,
                           const RenderContext &renderCtx) const {
  if (!renderCtx.textures.valid(cached_))
    return;
  renderCtx.renderer.draw(renderCtx.textures.get(cached_), nullptr, &rect);
}

void UITextContent::update(ResourceContext &resourceCtx, const float) {
  if (owner_ && owner_->dirty()) {
    SDL_Surface *surface =
        resourceCtx.fonts.getText(text_, color_, size_, wrapWidth_);
    cached_ =
        resourceCtx.textures.loadFromSurface(resourceCtx.renderer, surface);
  }
}

std::string UITextContent::text() const { return text_; }

void UITextContent::text(const std::string &text) {
  if (text == text_)
    return;
  text_ = text;

  if (owner_)
    owner_->markDirty(Dirty::Layout);
}

SDL_Color UITextContent::color() const { return color_; }

void UITextContent::color(const SDL_Color &color) {
  if (color.r == color_.r && color.g == color_.g && color.b == color_.b &&
      color.a == color_.a)
    return;
  color_ = color;

  if (owner_)
    owner_->markDirty(Dirty::Render);
}

FontManager::FontSize UITextContent::size() const { return size_; }

void UITextContent::size(FontManager::FontSize size) {
  if (size == size_)
    return;
  size_ = size;

  if (owner_)
    owner_->markDirty(Dirty::Layout);
}

float UITextContent::wrapWidth() const { return wrapWidth_; }

void UITextContent::wrapWidth(const float wrapWidth) {
  if (wrapWidth == wrapWidth_)
    return;
  wrapWidth_ = wrapWidth;

  if (owner_)
    owner_->markDirty(Dirty::Layout);
}
