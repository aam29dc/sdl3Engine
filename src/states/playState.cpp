#include "state/playState.hpp"
#include "core/context/frame.hpp"
#include "render/rect.hpp"
#include "ui/hud.hpp"
#include <iostream>
#include <memory>

PlayState::PlayState() {}
PlayState::~PlayState() {}

void PlayState::onEnter(UpdateContext &) {
  std::cout << "Enter playstate.\n";
  auto e = entities_.spawn(std::make_unique<Entity>());
  entities_.entity(e).renderable(std::make_unique<Rect>());
}

void PlayState::onExit(UpdateContext &) {
  std::cout << "Exit playstate.\n";
  entities_.clear();
}

void PlayState::handleEvents(FrameContext &) {}
HUDData PlayState::update(UpdateContext &, const float dt) {
  entities_.update(dt);
  entities_.removeDead();
  return HUDData{123};
}

void PlayState::render(const RenderContext &renderCtx) const {
  renderSystem_.render(entities_, renderCtx, camera_);
}

ActionState &PlayState::actions() { return actions_; }

const ActionState &PlayState::actions() const { return actions_; }
