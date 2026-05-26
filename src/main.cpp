#include "core/engine.hpp"

int main() {
  i32 windowWidth = 1440;
  i32 windowHeight = 900;
  Engine engine;

  if (!engine.init(windowWidth, windowHeight)) {
    return 1;
  }

  engine.run();

  return 0;
}
