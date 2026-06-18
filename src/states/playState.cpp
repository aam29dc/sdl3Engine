#include "state/playState.hpp"
#include "core/context/frame.hpp"
#include "core/context/update.hpp"
#include "io/tiledloader.hpp"
#include "ui/hud.hpp"
#include <iostream>

PlayState::PlayState() {}
PlayState::~PlayState() {}

void PlayState::onEnter(UpdateContext &updateCtx) {
  std::cout << "Enter playstate.\n";
  //  auto e = world_.entities.spawn(std::make_unique<Entity>());
  //  world_.entities.entity(e).renderable(std::make_unique<Rect>());
  world_.map = TiledLoader::load("assets/maps/map1.tmj", updateCtx.resouceCtx);
}

void PlayState::onExit(UpdateContext &) {
  std::cout << "Exit playstate.\n";
  world_.entities.clear();
}

void PlayState::handleEvents(FrameContext &) {}
HUDData PlayState::update(UpdateContext &, const float dt) {
  world_.entities.update(dt);
  world_.entities.removeDead();
  return HUDData{123};
}

void PlayState::render(const RenderContext &renderCtx) const {
  renderSystem_.renderMap(world_.map, renderCtx, camera_);
  renderSystem_.renderEntities(world_.entities, renderCtx, camera_);
}

ActionState &PlayState::actions() { return actions_; }

const ActionState &PlayState::actions() const { return actions_; }
