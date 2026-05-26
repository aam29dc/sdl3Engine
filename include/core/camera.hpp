#pragma once
#include "core/types.hpp"

class Camera {
private:
  Float2 pos_{0.0f, 0.0f};
  Float2 size_{1440.0f, 900.0f};
  float zoom_ = 1.0f;

public:
  Camera(const Float2 &size);
  ~Camera() = default;

  void move(const Float2 dt);

  SDL_FRect worldToScreen(const SDL_FRect worldRect);
  SDL_FRect screenToWorld(const SDL_FRect rect);

  void setPosition(const Float2 pos);
  void setSize(const Float2 value);
  void setZoom(const float value);

  Float2 position() const;
  Float2 size() const;
  float zoom() const;
};
