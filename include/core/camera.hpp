#pragma once
#include "core/types.hpp"

class Camera {
private:
  Float2 pos_{0.0f, 0.0f};
  Float2 size_{1440.0f, 900.0f};
  float zoom_ = 1.0f;

public:
  Camera(const Float2 &size = {1440.0f, 900.0f});
  ~Camera() = default;

  Camera(const Camera &) = default;
  Camera &operator=(const Camera &) = default;
  Camera(Camera &&) = default;
  Camera &operator=(Camera &&) = default;

  void move(const Float2 dt);

  SDL_FRect worldToScreen(const SDL_FRect &worldRect) const;
  SDL_FRect screenToWorld(const SDL_FRect &rect) const;

  void setPosition(const Float2 pos); // set camera pos in world
  void setSize(const Float2 size);    // set viewport size
  void setZoom(const float zoom);     // scale the world
  void follow(const SDL_FRect &rect);

  Float2 position() const;
  Float2 size() const;
  float zoom() const;
};
