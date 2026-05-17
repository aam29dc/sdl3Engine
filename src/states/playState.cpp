#include "states/playState.hpp"
#include "core/engine.hpp"
#include <iostream>

PlayState::PlayState() {}
PlayState::~PlayState() {}

void PlayState::onEnter(Engine &) { std::cout << "Enter playstate.\n"; }
void PlayState::onExit(Engine &) { std::cout << "Exit playstate.\n"; }

void PlayState::handleEvents(Engine &) {}
void PlayState::update(Engine &, const float) {}
void PlayState::render(const Engine &) const {}
