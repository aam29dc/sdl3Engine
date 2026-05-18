#pragma once
#include "core/handles.hpp"
#include "core/render_context.hpp"
#include "ui/elements/element.hpp"

class UILabel : public UIElement {
private:
  std::string text_;
  TextureHandle handle_{0};

public:
  UILabel(RenderContext &ctx, const SDL_FRect &rect, const std::string &text);
  virtual ~UILabel() override = default;

  //  virtual void handleEvents(const Input &input) override;
  virtual void update(const float dt) override;
  virtual void render(const RenderContext &ctx) const override;

  void text(const RenderContext &ctx, const std::string &newText);

  const std::string &text() { return text_; }
  const TextureHandle &handle() { return handle_; };
};
