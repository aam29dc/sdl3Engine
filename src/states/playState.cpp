#include "states/playState.hpp"
#include "core/frame_context.hpp"
#include <iostream>

PlayState::PlayState() {}
PlayState::~PlayState() {}

void PlayState::onEnter(UpdateContext &) { std::cout << "Enter playstate.\n"; }
void PlayState::onExit(UpdateContext &) { std::cout << "Exit playstate.\n"; }

void PlayState::handleEvents(FrameContext &) {}
HUDData PlayState::update(UpdateContext &, const float) { return {123}; }
void PlayState::render(const RenderContext &) const {}
