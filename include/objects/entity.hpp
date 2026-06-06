#pragma once
#include "core/types.hpp"
#include "render/renderable.hpp"
#include <SDL3/SDL_rect.h>
#include <memory>

class Entity {
protected:
  Float2 pos_{0, 0};
  Float2 size_{32, 32};
  bool alive_{true};
  std::unique_ptr<Renderable> renderable_;

public:
  Entity() = default;
  virtual ~Entity() = default;

  virtual void update(const float dt);

  bool alive() const;
  void destroy();

  Float2 &pos();
  const Float2 &pos() const;

  Float2 &size();
  const Float2 &size() const;

  SDL_FRect rect() const;

  const Renderable *renderable() const;
  void renderable(std::unique_ptr<Renderable> renderable);
};
