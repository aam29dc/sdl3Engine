#pragma once
#include "states/gameState.hpp"
#include "ui/hud.hpp"

class PlayState : public GameState {
private:
public:
  HUDData hud_{};
  PlayState();
  ~PlayState();

  void handleEvents(FrameContext &frameCtx) override;
  HUDData update(UpdateContext &updateCtx, const float dt) override;
  void render(const RenderContext &renderCtx) const override;

  void onEnter(UpdateContext &updateCtx) override;
  void onExit(UpdateContext &updateCtx) override;
};
