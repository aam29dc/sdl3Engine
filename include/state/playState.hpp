#pragma once
#include "core/camera.hpp"
#include "render/rendersystem.hpp"
#include "state/gameState.hpp"
#include "ui/hud.hpp"
#include "world/entitymanager.hpp"

class PlayState : public GameState {
private:
  HUDData hud_{};
  Camera camera_{};
  EntityManager entities_;
  RenderSystem renderSystem_;

public:
  PlayState();
  ~PlayState();

  void handleEvents(FrameContext &frameCtx) override;
  HUDData update(UpdateContext &updateCtx, const float dt) override;
  void render(const RenderContext &renderCtx) const override;

  void onEnter(UpdateContext &updateCtx) override;
  void onExit(UpdateContext &updateCtx) override;
};
