#include "core/game.hpp"

int main() {
  i32 windowWidth = 1440;
  i32 windowHeight = 900;
  Game game;

  if (!game.init(windowWidth, windowHeight)) {
    return 1;
  }

  game.run();

  return 0;
}
