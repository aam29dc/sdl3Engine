#include "core/game.hpp"
#include "core/window.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>

bool Game::init(const i32 windowWidth, const i32 windowHeight) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("Init failed: %s", SDL_GetError());
    return false;
  }
  return engine_.init(windowWidth, windowHeight);
}

void Game::run() {
  while (!quit_) {
    SDL_Event e;
    engine_.input().beginFrame(); // calls getKeyBoardState
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT || engine_.window().getQuit()) {
        quit_ = true;
      }
      engine_.handleEvents(e);
    }
    engine_.update(dt_);
    engine_.render();
  }
}
