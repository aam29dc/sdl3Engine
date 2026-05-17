#pragma once
#include "states/gameState.hpp"
#include "ui/hud.hpp"

class PlayState : public GameState {
private:
public:
  HUDData hud_{};
  PlayState();
  ~PlayState();

  void handleEvents(Engine &engine) override;
  HUDData update(Engine &engine, const float dt) override;
  void render(const Engine &engine) const override;

  void onEnter(Engine &engine) override;
  void onExit(Engine &engine) override;
};
