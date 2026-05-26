#pragma once
#include "ui/elements/element.hpp"
#include "ui/eventsink.hpp"
#include <SDL3/SDL_events.h>
#include <memory>
#include <vector>

class Engine;
class Renderer;
class Input;

class UIContainer : public UIElement {
private:
  std::vector<std::unique_ptr<UIElement>> children_;

public:
  UIContainer(const UITransform &transform);
  virtual ~UIContainer() override = default;

  UIElement &add(std::unique_ptr<UIElement> ele);

  void handleEvents(const Input &input, const UISpace &space,
                    UIEventSink &sink) override;
  void render(const RenderContext &ctx) const override;
  void update(const float dt) override;
};
