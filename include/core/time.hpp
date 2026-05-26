#pragma once
#include "core/types.hpp"

class Time {
private:
  u64 last_ = 0;
  float dt_ = 0.0f;
  float elapsed_ = 0.0f;
  float timescale_ = 1.0f;

public:
  Time() = default;
  ~Time() = default;

  void init();

  void tick();

  float dt() const { return dt_; }
  float elapsed() const { return elapsed_; }

  void setTimescale(float timescale) { timescale_ = timescale; }
  float timescale() const { return timescale_; }
};
