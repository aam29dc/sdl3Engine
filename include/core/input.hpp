#pragma once
#include "core/types.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>
#include <array>

class Input {
public:
  enum class MouseButton : u8 { Middle = 0, Left = 1, Right = 2, Count = 3 };
  Input() = default;
  Input(const Input &) = delete;
  Input &operator=(const Input &) = delete;
  Input(Input &&) = delete;
  Input &operator=(Input &&) = delete;

  void beginFrame();
  void handleEvent(const SDL_Event &e);

  bool isKeyDown(SDL_Scancode key) const;
  bool isKeyPressed(SDL_Scancode key) const;
  bool isKeyReleased(SDL_Scancode key) const;

  bool isMouseDown(MouseButton button) const;
  bool isMousePressed(MouseButton button) const;
  bool isMouseReleased(MouseButton button) const;

  Int2 getMousePos() const;

private:
  std::array<bool, SDL_SCANCODE_COUNT> keys_{};
  std::array<bool, SDL_SCANCODE_COUNT> prevKeys_{};

  std::array<bool, 3> mouse_{};
  std::array<bool, 3> prevMouse_{};

  SDL_FPoint mousePos_{};
};
