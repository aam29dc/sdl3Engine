#include <SDL3/SDL_events.h>
class Engine;

class GameState {
private:
public:
  virtual ~GameState() = default;

  virtual void handleEvents(Engine &engine) = 0;
  virtual void update(Engine &engine, const float dt) = 0;
  virtual void render(const Engine &engine) const = 0;

  virtual void onEnter(Engine &engine) = 0;
  virtual void onExit(Engine &engine) = 0;
};
