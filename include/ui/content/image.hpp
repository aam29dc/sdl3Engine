#pragma once
#include "core/handles.hpp"
#include "ui/content/content.hpp"

class UIImageContent : public UIContent {
private:
  TextureHandle handle_;

public:
  explicit UIImageContent(TextureHandle handle);

  void set(TextureHandle h);

  void render(const SDL_FRect &rect, const RenderContext &ctx) const override;
};
