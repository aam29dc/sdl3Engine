#pragma once
#include "core/input.hpp"
#include "ui/cmds.hpp"
#include "ui/elements/element.hpp"

class UIButton : public UIElement {
private:
  SDL_Color hover_{Color::Blue};
  SDL_Color click_{Color::Red};

  bool hovered_{false};
  bool pressed_{false};
  bool clicked_{false};
  UICmd cmd_{UICmd::None};

public:
  UIButton(const SDL_FRect &rect, const UICmd cmd);
  virtual ~UIButton() override = default;

  virtual void handleEvents(const Input &input) override;
  virtual void update(const float dt) override;
  virtual void render(Renderer &renderer) const override;

  bool clicked() const { return clicked_; }
  bool pressed() const { return pressed_; }
  bool hovererd() const { return hovered_; }
  UICmd cmd() const { return cmd_; }
};
