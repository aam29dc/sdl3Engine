#pragma once
#include <SDL3/SDL_events.h>
struct Binds;
struct Console;
class InputBuffer;

class InputRouter {
private:
  Binds &binds_;
  InputBuffer &buffer_;

public:
  InputRouter(const InputRouter &) = delete;
  InputRouter &operator=(const InputRouter &) = delete;
  InputRouter(InputRouter &&) = delete;
  InputRouter &operator=(InputRouter &&) = delete;

  InputRouter(Binds &binds, InputBuffer &buffer);
  void handle(const SDL_Event &e);
};
