#pragma once
#include <SDL3/SDL_events.h>

class Engine;
struct HUDData;
struct FrameContext;
struct RenderContext;
struct UpdateContext;

class GameState {
private:
public:
  virtual ~GameState() = default;

  virtual void handleEvents(FrameContext &frameCtx) = 0;
  virtual HUDData update(UpdateContext &updateCtx, const float dt) = 0;
  virtual void render(const RenderContext &renderCtx) const = 0;

  virtual void onEnter(UpdateContext &updateCtx) = 0;
  virtual void onExit(UpdateContext &updateCtx) = 0;
};
