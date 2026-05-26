#include "core/window.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_video.h>

Window::~Window() {
  quit_ = true;
  if (window_)
    SDL_DestroyWindow(window_);
  window_ = nullptr;
}

bool Window::init(const i32 windowWidth, const i32 windowHeight) {
  windowWidth_ = windowWidth;
  windowHeight_ = windowHeight;
  window_ =
      SDL_CreateWindow("sdl3Game", windowWidth_, windowHeight_,
                       SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
  if (!window_) {
    SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
    return false;
  }
  return true;
}

void Window::handleEvent(const SDL_Event &e) {
  switch (e.type) {
  case SDL_EVENT_WINDOW_RESIZED:
  case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED: {
    int width = 0;
    int height = 0;

    SDL_GetWindowSize(window_, &width, &height);
    windowWidth_ = width;
    windowHeight_ = height;
    break;
  }

  case SDL_EVENT_WINDOW_MOUSE_ENTER:
    mouseFocus_ = true;
    break;

  case SDL_EVENT_WINDOW_MOUSE_LEAVE:
    mouseFocus_ = false;
    break;

  case SDL_EVENT_WINDOW_FOCUS_GAINED:
    keyboardFocus_ = true;
    break;

  case SDL_EVENT_WINDOW_FOCUS_LOST:
    keyboardFocus_ = false;
    break;

  case SDL_EVENT_WINDOW_MINIMIZED:
    minimized_ = true;
    break;

  case SDL_EVENT_WINDOW_MAXIMIZED:
    minimized_ = false;
    break;

  case SDL_EVENT_WINDOW_RESTORED:
    minimized_ = false;
    break;

  case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
    quit_ = true;
    break;

  default:
    break;
  }
}

SDL_Window *Window::get() { return window_; }

i32 Window::getWidth() const { return windowWidth_; }

i32 Window::getHeight() const { return windowHeight_; }

bool Window::getMouseFocus() const { return mouseFocus_; }

bool Window::getKeyboardFocus() const { return keyboardFocus_; }

bool Window::getFullscreen() const { return fullScreen_; }

bool Window::getMinimized() const { return minimized_; }

bool Window::getQuit() const { return quit_; }
