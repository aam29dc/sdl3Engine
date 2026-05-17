#include "core/engine.hpp"
#include "core/renderer.hpp"
#include "core/window.hpp"
#include "states/playState.hpp"
#include "ui/colors.hpp"
#include "ui/menu/id.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <memory>

bool Engine::init(const i32 windowWidth, const i32 windowHeight) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("Init failed: %s", SDL_GetError());
    return false;
  }
  window_ = std::make_unique<Window>();
  renderer_ = std::make_unique<Renderer>();

  if (!window_->init(windowWidth, windowHeight)) {
    SDL_Quit();
    return false;
  }

  if (!renderer_->init(window_.get())) {
    window_.reset();
    SDL_Quit();
    return false;
  }

  // play_ = std::make_unique<PlayState>();
  // play_->onEnter(*this);

  return true;
}

void Engine::pushEvent(const UICmd cmd) { events_.push(cmd); }

void Engine::handleEvents(const SDL_Event &e) {
  window_->handleEvent(e);
  input_.handleEvent(e);
  events_ = ui_.handleEvents(input_);
  if (play_)
    play_->handleEvents(*this);
}

void Engine::update(const float dt) {
  while (!events_.empty()) {
    switch (events_.front()) {
    case UICmd::None:
    default:
      break;
    case UICmd::Start:
      if (!play_) {
        play_ = std::make_unique<PlayState>();
        play_->onEnter(*this);
        ui_.playState(play_ != nullptr);
        ui_.pop();
      }
      break;
    case UICmd::Disconnect:
      if (play_) {
        play_->onExit(*this);
        play_.reset();
        ui_.playState(play_ == nullptr);
        ui_.push(MenuID::MainMenu);
      }
      break;
    case UICmd::Reload:
      if (!play_) {
        play_->onExit(*this);
        play_.reset();
        play_ = std::make_unique<PlayState>();
      }
      break;
    }
    events_.pop();
  }
  if (play_)
    play_->update(*this, dt);
  ui_.update(dt);
}

void Engine::render() const {
  renderer_->setDrawColor(Color::White);
  renderer_->clear();

  if (play_)
    play_->render(*this);
  ui_.render(*renderer_);

  renderer_->present();
}

Engine::Engine() = default;

Engine::~Engine() {
  if (play_) {
    play_->onExit(*this);
  }
}
