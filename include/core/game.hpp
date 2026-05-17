#pragma once
#include "core/engine.hpp"

class Game {
private:
  Engine engine_;
  bool quit_ = false;
  float dt_ = 0.0f;

public:
  Game() = default;
  ~Game() = default;

  Game(const Game &) = delete;
  Game &operator=(const Game &) = delete;
  Game(Game &&) = delete;
  Game &operator=(Game &&) = delete;

  bool init(const i32 windowWidth, const i32 windowHeight);
  void run();
};
