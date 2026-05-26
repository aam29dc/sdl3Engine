#pragma once
#include "core/handles.hpp"
#include "ui/style/style.hpp"

class UITexturedStyle : public UIStyle {
private:
  TextureHandle texture_;

public:
  explicit UITexturedStyle(TextureHandle texture);

  void render(const SDL_FRect &rect, const UIStyleParams &params,
              const RenderContext &renderCtx) const override;
};
