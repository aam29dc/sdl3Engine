#include "core/inputrouter.hpp"
#include "core/console.hpp"
#include "core/context/command.hpp"
#include "managers/binds.hpp"

InputRouter::InputRouter(Binds &binds, Console &console)
    : binds_(binds), console_(console) {}

void InputRouter::handle(CommandContext &cmdCtx, const SDL_Event &e) {
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

    console_.execute(cmdCtx, *cmd);
    break;
  }
  }
}
