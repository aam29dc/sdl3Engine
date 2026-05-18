#pragma once
#include "core/render_context.hpp"
#include "ui/cmds.hpp"
#include <SDL3/SDL_events.h>
#include <memory>
#include <queue>
#include <vector>

struct RenderContext;
class UIElement;
class Engine;
class Renderer;
class Input;

class UIContainer {
private:
  std::vector<std::unique_ptr<UIElement>> eles_;

public:
  UIContainer();
  ~UIContainer();

  void add(std::unique_ptr<UIElement> ele);

  std::queue<UICmd> handleEvents(const Input &input);
  void render(const RenderContext &ctx) const;
  void update(const float dt);
};
