#include "core/camera.hpp"

Camera::Camera(const Float2 &size) : size_(size) {}
void Camera::move(const Float2 dt) { pos_ += dt; }

SDL_FRect Camera::worldToScreen(const SDL_FRect &worldRect) const {
  return {(worldRect.x - pos_.x) * zoom_, (worldRect.y - pos_.y) * zoom_,
          worldRect.w * zoom_, worldRect.h * zoom_};
}
SDL_FRect Camera::screenToWorld(const SDL_FRect &rect) const {
  return {(rect.x / zoom_) + pos_.x, (rect.y / zoom_) + pos_.y, rect.w / zoom_,
          rect.h / zoom_};
}

void Camera::setPosition(const Float2 pos) { pos_ = pos; }
void Camera::setSize(const Float2 size) { size_ = size; }
void Camera::setZoom(const float zoom) { zoom_ = zoom; }

void Camera::follow(const SDL_FRect &rect) {
  pos_ = {rect.x - size_.x / 2.0f + rect.w / 2.0f,
          rect.y - size_.y / 2.0f + rect.h / 2.0f};
}

Float2 Camera::position() const { return pos_; }
Float2 Camera::size() const { return size_; }
float Camera::zoom() const { return zoom_; }
