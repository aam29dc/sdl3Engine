#pragma once
#include "core/context/render.hpp"
#include "core/context/resource.hpp"
#include "core/handles.hpp"
#include "managers/font.hpp"
#include "ui/content/content.hpp"
#include "ui/elements/element.hpp"
#include <SDL3/SDL_render.h>
#include <string>

class UITextContent : public UIContent {
private:
  std::string text_;
  mutable TextureHandle cached_{};
  SDL_Color color_{0, 0, 0, 255};
  FontManager::FontSize size_{FontManager::FontSize::Medium};
  float wrapWidth_ = 0.0f;

public:
  UITextContent(
      UIElement *owner, const std::string &text,
      const FontManager::FontSize size = FontManager::FontSize::Medium);

  std::string text() const;
  void text(const std::string &text);
  SDL_Color color() const;
  void color(const SDL_Color &color);
  FontManager::FontSize size() const;
  void size(const FontManager::FontSize size);
  float wrapWidth() const;
  void wrapWidth(const float wrapWidth);

  void render(const SDL_FRect &rect, const RenderContext &ctx) const override;
  void update(ResourceContext &resourceCtx, const float dt) override;
};
