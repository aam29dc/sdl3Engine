#include "core/time.hpp"
#include <SDL3/SDL_timer.h>

void Time::init() { last_ = SDL_GetPerformanceCounter(); }

void Time::tick() {
  u64 now = SDL_GetPerformanceCounter();
  u64 freq = SDL_GetPerformanceFrequency();
  dt_ = (now - last_) / (float)freq;
  last_ = now;
  dt_ *= timescale_;
  elapsed_ += dt_;
}
