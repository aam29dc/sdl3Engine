#pragma once
#include "core/context/command.hpp"
#include <SDL3/SDL_events.h>
struct Binds;
struct Console;

class InputRouter {
private:
  Binds &binds_;
  Console &console_;

public:
  InputRouter(const InputRouter &) = delete;
  InputRouter &operator=(const InputRouter &) = delete;
  InputRouter(InputRouter &&) = delete;
  InputRouter &operator=(InputRouter &&) = delete;

  InputRouter(Binds &binds, Console &console);
  void handle(CommandContext &cmdCtx, const SDL_Event &e);
};
