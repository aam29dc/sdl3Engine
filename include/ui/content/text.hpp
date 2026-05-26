#pragma once
#include "core/handles.hpp"
#include "managers/font.hpp"
#include "ui/content/content.hpp"
#include "ui/dirty.hpp"
#include <SDL3/SDL_render.h>
#include <string>

class UITextContent : public UIContent {
private:
  std::string text_;
  mutable TextureHandle cached_;
  mutable Dirty dirty_ = Dirty::None;

  FontManager::FontSize size_;
  float wrapWidth_ = 0.0f;

public:
  UITextContent(std::string text,
                FontManager::FontSize size = FontManager::FontSize::Medium);

  void setText(const std::string &text);

  void render(const SDL_FRect &rect, const RenderContext &ctx) const override;
  void update(const float dt) override;
};
