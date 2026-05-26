#pragma once
#include "core/console.hpp"
#include "core/input.hpp"
#include "ui/eventsink.hpp"

#include <memory>

class UI;
class FontManager;
class TextureManager;
class Renderer;
class Window;
class GameState;

class Engine {
private:
  std::unique_ptr<Window> window_;
  std::unique_ptr<Renderer> renderer_;
  Input input_;

  std::unique_ptr<FontManager> fonts_;
  std::unique_ptr<TextureManager> textures_;
  std::unique_ptr<UI> ui_;

  std::unique_ptr<GameState> play_;

  Console console_;
  UIEventSink sink_;

public:
  Engine();
  ~Engine();

  Window &window() { return *window_; }

  Renderer &renderer() { return *renderer_; }
  const Renderer &renderer() const { return *renderer_; }

  Input &input() { return input_; }
  const Input &input() const { return input_; }

  TextureManager &textures() { return *textures_; }
  const TextureManager &textures() const { return *textures_; }

  FontManager &fonts() { return *fonts_; }
  const FontManager &fonts() const { return *fonts_; }

  Console &console() { return console_; }
  const Console &console() const { return console_; }

  Engine(const Engine &) = delete;
  Engine &operator=(const Engine &) = delete;
  Engine(Engine &&) = delete;
  Engine &operator=(Engine &&) = delete;

  bool init(const i32 windowWidth, const i32 windowHeight);
  void handleEvents(const SDL_Event &e);
  void update(const float dt);
  void render() const;
};
