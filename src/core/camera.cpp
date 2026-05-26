#include "core/camera.hpp"

void Camera::move(const Float2 dt) { pos_ += dt; }

SDL_FRect Camera::worldToScreen(const SDL_FRect worldRect) {
  return { worldRect.x }
}
SDL_FRect Camera::screenToWorld(const SDL_FRect rect);

void Camera::setPosition(const Float2 pos);
void Camera::setSize(const Float2 value);
void Camera::setZoom(const float value);

Float2 Camera::position() const;
Float2 Camera::size() const;
float Camera::zoom() const;
