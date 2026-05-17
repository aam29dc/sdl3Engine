#pragma once
#include "states/gameState.hpp"

class PlayState : public GameState {
private:
public:
  struct HUDData {
    // hp, armor, exp, score, ammo ...
  };
  PlayState();
  ~PlayState();

  void handleEvents(Engine &engine) override;
  void update(Engine &engine, const float dt) override;
  void render(const Engine &engine) const override;

  void onEnter(Engine &engine) override;
  void onExit(Engine &engine) override;
};
