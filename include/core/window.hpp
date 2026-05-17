#pragma once
#include "core/types.hpp"
class SDL_Window;
#include <SDL3/SDL_events.h>

class Window {
private:
  i32 windowHeight_ = 0;
  i32 windowWidth_ = 0;

  bool mouseFocus_ = false;
  bool keyboardFocus_ = false;
  bool fullScreen_ = false;
  bool minimized_ = false;
  bool quit_ = false;

  SDL_Window *window_ = nullptr;

public:
  Window() = default;
  ~Window();

  bool init(const i32 windowWidth, const i32 windowHeight);
  void handleEvent(const SDL_Event &e);

  SDL_Window *get();

  i32 getWidth() const;
  i32 getHeight() const;
  bool getMouseFocus() const;
  bool getKeyboardFocus() const;
  bool getFullscreen() const;
  bool getMinimized() const;
  bool getQuit() const;
};
