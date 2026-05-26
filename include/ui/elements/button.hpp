#pragma once
#include "core/input.hpp"
#include "ui/elements/element.hpp"
#include "ui/eventsink.hpp"

class UIButton : public UIElement {
private:
  bool clicked_{false};
  UICmd cmd_{UICmd::None};

public:
  UIButton(const UITransform &transform, const UICmd cmd);
  virtual ~UIButton() override = default;

  virtual void handleEvents(const Input &input, UIEventSink &sink) override;

  virtual void update(const UISpace &space, const float dt) override;

  bool clicked() const { return clicked_; }
  bool pressed() const { return styleParams_.pressed; }
  bool hovererd() const { return styleParams_.hovered; }
  UICmd cmd() const { return cmd_; }
};
