#include "core/input.hpp"
#include <cstring>

void Input::beginFrame() {
  std::memcpy(prevKeys_.data(), keys_.data(), SDL_SCANCODE_COUNT);

  const bool *state = SDL_GetKeyboardState(nullptr);
  std::memcpy(keys_.data(), state, SDL_SCANCODE_COUNT);

  std::memcpy(prevMouse_.data(), mouse_.data(), mouse_.size());
}

void Input::handleEvent(const SDL_Event &e) {
  switch (e.type) {
  case SDL_EVENT_MOUSE_BUTTON_DOWN:
    if (e.button.button < static_cast<u8>(MouseButton::Count)) {
      mouse_[e.button.button] = true;
    }
    break;
  case SDL_EVENT_MOUSE_BUTTON_UP:
    if (e.button.button < static_cast<u8>(MouseButton::Count)) {
      mouse_[e.button.button] = false;
    }
    break;
  case SDL_EVENT_MOUSE_MOTION:
    mousePos_.x = e.motion.x;
    mousePos_.y = e.motion.y;
    break;
  default:
    break;
  }
}

bool Input::isKeyDown(SDL_Scancode key) const { return keys_[key]; }
bool Input::isKeyPressed(SDL_Scancode key) const {
  return keys_[key] && !prevKeys_[key];
}
bool Input::isKeyReleased(SDL_Scancode key) const {
  return !keys_[key] && prevKeys_[key];
}
bool Input::isMouseDown(MouseButton button) const { return mouse_[(u8)button]; }
bool Input::isMousePressed(MouseButton button) const {
  return mouse_[(u8)button] && !prevMouse_[(u8)button];
}
bool Input::isMouseReleased(MouseButton button) const {
  return !mouse_[(u8)button] && prevMouse_[(u8)button];
}

Int2 Input::getMousePos() const {
  return {static_cast<i32>(mousePos_.x), static_cast<i32>(mousePos_.y)};
}
