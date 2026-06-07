#pragma once
#include "core/context/resource.hpp"
#include "ui/elements/element.hpp"
#include "ui/eventsink.hpp"
#include <SDL3/SDL_events.h>
#include <memory>
#include <vector>

class Engine;
class Renderer;
class Input;
struct UISpace;

class UIContainer : public UIElement {
private:
  std::vector<std::unique_ptr<UIElement>> children_;

public:
  UIContainer(const UITransform &transform);
  virtual ~UIContainer() override = default;

  UIElement &add(std::unique_ptr<UIElement> ele);

  void handleEvents(const Input &input, UIEventSink &sink) override;
  void render(const RenderContext &ctx) const override;
  void update(ResourceContext &resourceCtx, const UISpace &space,
              const float dt) override;
};
