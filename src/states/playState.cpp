#include "states/playState.hpp"
#include "core/engine.hpp"
#include <iostream>

PlayState::PlayState() {}
PlayState::~PlayState() {}

void PlayState::onEnter(Engine &) { std::cout << "Enter playstate.\n"; }
void PlayState::onExit(Engine &) { std::cout << "Exit playstate.\n"; }

void PlayState::handleEvents(Engine &) {}
HUDData PlayState::update(Engine &, const float) { return {123}; }
void PlayState::render(const RenderContext &) const {}
