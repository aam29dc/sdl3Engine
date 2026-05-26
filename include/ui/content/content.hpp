#pragma once

struct RenderContext;
struct SDL_FRect;

class UIContent {
public:
  virtual ~UIContent() = default;

  virtual void render(const SDL_FRect &rect,
                      const RenderContext &ctx) const = 0;
  virtual void update(const float dt) = 0;
};
