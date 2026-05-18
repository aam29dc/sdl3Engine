#pragma once
#include "core/input.hpp"
#include "managers/font.hpp"
#include "managers/texture.hpp"
#include "ui/cmds.hpp"
#include "ui/ui.hpp"
#include <memory>
#include <queue>
class Renderer;
class Window;
class GameState;

class Engine {
private:
  std::unique_ptr<Window> window_;
  std::unique_ptr<Renderer> renderer_;
  Input input_;
  FontManager fonts_;

  std::unique_ptr<UI> ui_;
  std::queue<UICmd> events_;

  std::unique_ptr<GameState> play_;

  TextureManager textures_;

public:
  Engine();
  ~Engine();

  Window &window() { return *window_; };
  Renderer &renderer() { return *renderer_; }
  const Renderer &renderer() const { return *renderer_; }
  //  StateMachine &stateMachine() { return stateMachine_; }
  Input &input() { return input_; }
  const Input &input() const { return input_; }
  TextureManager &textures() { return textures_; }
  const TextureManager &textures() const { return textures_; }
  FontManager &fonts() { return fonts_; }
  const FontManager &fonts() const { return fonts_; }

  Engine(const Engine &) = delete;
  Engine &operator=(const Engine &) = delete;
  Engine(Engine &&) = delete;
  Engine &operator=(Engine &&) = delete;

  bool init(const i32 windowWidth, const i32 windowHeight);

  void pushEvent(const UICmd cmd);

  void handleEvents(const SDL_Event &e);
  void update(const float dt);
  void render() const;
};
