#include "input/input.hpp"
#include "core/types.hpp"
#include <cstring>

void Input::beginFrame() {
  SDL_PumpEvents();

  prevKeys_ = keys_;

  int numKeys = 0;
  const bool *state = SDL_GetKeyboardState(&numKeys);

  for (int i = 0; i < numKeys && i < SDL_SCANCODE_COUNT; i++) {
    keys_[i] = state[i];
  }

  prevMouse_ = mouse_;
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

SDL_Scancode Input::getFirstKeyDown() const {
  for (int i = 0; i < SDL_SCANCODE_COUNT; ++i) {
    if (keys_[i]) {
      return static_cast<SDL_Scancode>(i);
    }
  }
  return SDL_SCANCODE_UNKNOWN;
}

SDL_Scancode Input::getFirstKeyReleased() const {
  for (int i = 0; i < SDL_SCANCODE_COUNT; ++i) {
    if (prevKeys_[i] && !keys_[i]) {
      return static_cast<SDL_Scancode>(i);
    }
  }
  return SDL_SCANCODE_UNKNOWN;
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
