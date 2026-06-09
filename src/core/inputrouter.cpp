#include "core/inputrouter.hpp"
#include "core/inputbuffer.hpp"
#include "managers/binds.hpp"

InputRouter::InputRouter(Binds &binds, InputBuffer &buffer)
    : binds_(binds), buffer_(buffer) {}

void InputRouter::handle(const SDL_Event &e) {
  switch (e.type) {
  default:
    break;
  case SDL_EVENT_KEY_UP:
  case SDL_EVENT_KEY_DOWN: {
    // ignore SDL key repeat events
    if (e.type == SDL_EVENT_KEY_DOWN && e.key.repeat)
      return;

    SDL_Scancode key = e.key.scancode;
    bool pressed = (e.type == SDL_EVENT_KEY_DOWN);

    const std::string *cmd = binds_.get(key, pressed);
    if (!cmd)
      return;

    buffer_.push(*cmd);
    break;
  }
  }
}
