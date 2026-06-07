#pragma once

struct RenderContext;
struct SDL_FRect;
class UIElement;
struct ResourceContext;

class UIContent {
protected:
  UIElement *owner_ = nullptr;

public:
  virtual ~UIContent() = default;

  virtual void render(const SDL_FRect &rect,
                      const RenderContext &ctx) const = 0;
  virtual void update(ResourceContext &resourceCtx, const float dt) = 0;
};
