#include "core/engine.hpp"
#include "core/context/command.hpp"
#include "core/context/frame.hpp"
#include "core/context/render.hpp"
#include "core/context/resource.hpp"
#include "core/context/update.hpp"
#include "core/renderer.hpp"
#include "core/window.hpp"
#include "input/action_bind.hpp"
#include "input/commands.hpp"
#include "input/inputbuffer.hpp"
#include "input/inputrouter.hpp"
#include "resource/fontmanager.hpp"
#include "resource/texturemanager.hpp"
#include "state/playState.hpp"
#include "ui/colors.hpp"
#include "ui/eventsink.hpp"
#include "ui/layout.hpp"
#include "ui/menu/menu.hpp"
#include "ui/ui.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>
#include <memory>

void Engine::quit() { quit_ = true; }

void Engine::registerCommands() {
  console_.addCommand("clear", cmd_clear);
  console_.addCommand("echo", cmd_echo);
  console_.addCommand("quit", cmd_quit);
  console_.addCommand("exit", cmd_quit);
  console_.addCommand("timescale", cmd_timescale);
}

void Engine::registerActions() {
  bindAction(console_, "moveleft", play_->actions(), &ActionState::moveLeft);
  bindAction(console_, "moveright", play_->actions(), &ActionState::moveRight);
  bindAction(console_, "moveforward", play_->actions(),
             &ActionState::moveForward);
  bindAction(console_, "moveback", play_->actions(), &ActionState::moveBack);
}

bool Engine::init(const i32 windowWidth, const i32 windowHeight) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("Init failed: %s", SDL_GetError());
    return false;
  }

  time_.init();

  window_ = std::make_unique<Window>();
  renderer_ = std::make_unique<Renderer>();

  if (!window_->init(windowWidth, windowHeight)) {
    std::cout << "Window failed init." << std::endl;
    SDL_Quit();
    return false;
  }

  if (!renderer_->init(window_.get())) {
    std::cout << "renderer failed init." << std::endl;
    window_.reset();
    SDL_Quit();
    return false;
  }

  if (!TTF_Init()) {
    std::cout << "TTF_Init failed: " << SDL_GetError() << "\n";
    renderer_.reset();
    window_.reset();
    TTF_Quit();
    SDL_Quit();
    return false;
  }

  fonts_ = std::make_unique<FontManager>();

  if (!fonts_->init("assets/fonts/DejaVuSans.ttf")) {
    std::cout << "Fonts failed to init." << std::endl;
    renderer_.reset();
    window_.reset();
    SDL_Quit();
    return false;
  }

  textures_ = std::make_unique<TextureManager>();

  /*  const UISpace space = {(float)window_->getWidth(),
                           (float)window_->getHeight()};
  */
  ResourceContext resourceCtx = {*textures_, *fonts_, *renderer_};

  ui_ = std::make_unique<UI>(resourceCtx);

  CommandContext cmdCtx = {*this};
  console_.init(cmdCtx);
  registerCommands();
  registerActions();

  buffer_ = std::make_unique<InputBuffer>();
  router_ = std::make_unique<InputRouter>(binds_, *buffer_.get());

  //  play_ = std::make_unique<PlayState>();
  //  play_->onEnter(renderCtx);

  return true;
}

void Engine::run() {
  while (!quit_) {
    SDL_Event e;
    time_.tick();
    input().beginFrame(); // calls getKeyBoardState

    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT || window().getQuit())
        quit_ = true;

      handleEvents(e);
    }

    update(time_.dt());
    render();
  }
}

void Engine::handleEvents(const SDL_Event &e) {
  window_->handleEvent(e);
  input_.handleEvent(e);
  CommandContext cmdCtx = {*this};
  console_.handleEvents(cmdCtx, e, *window_);
  router_->handle(
      e); // router converts key event to cmd then pushes into inputBuffer
}

void Engine::processBuffer(CommandContext &cmdCtx) {
  std::vector<std::string> &buffer = buffer_->commands();

  for (auto &cmd : buffer) {
    console_.execute(cmdCtx, cmd);
  }
  buffer_->clear();
}

void Engine::update(float dt) {
  const UISpace space = {(float)window_->getWidth(),
                         (float)window_->getHeight()};

  FrameContext frameCtx = {*window_, input_};

  sink_.clear();
  ui_->handleEvents(input_, sink_);
  if (play_)
    play_->handleEvents(frameCtx);

  UpdateContext updateCtx = {*renderer_, *textures_, *fonts_};
  processSink(updateCtx);

  CommandContext cmdCtx = {*this};
  processBuffer(cmdCtx);

  HUDData hud{};
  if (play_)
    hud = play_->update(updateCtx, dt);

  ResourceContext resourceCtx = {*textures_, *fonts_, *renderer_};

  ui_->update(resourceCtx, space, hud, dt);
  console_.update(resourceCtx, space, dt);
}

void Engine::render() const {
  renderer_->setDrawColor(Color::White);
  renderer_->clear();

  const UISpace space = {(float)window_->getWidth(),
                         (float)window_->getHeight()};

  //  const float scale = getUniformScale(space);

  RenderContext renderCtx = {*renderer_, *textures_, *fonts_, space};

  if (play_)
    play_->render(renderCtx);
  ui_->render(renderCtx);
  console_.render(renderCtx);

  renderer_->present();
}

void Engine::processSink(UpdateContext &updateCtx) {
  for (const auto &e : sink_.events()) {

    switch (e.cmd) {

    case UICmd::None:
    default:
      break;

    case UICmd::Start:
      if (!play_) {
        play_ = std::make_unique<PlayState>();

        play_->onEnter(updateCtx);

        //        ui_->playState(true);
        ui_->pop();
      }
      break;

    case UICmd::Disconnect:
      if (play_) {
        play_->onExit(updateCtx);

        play_.reset();

        //       ui_->playState(false);
        ui_->push(MenuID::Main);
      }
      break;

    case UICmd::Reload:
      if (play_) {
        play_->onExit(updateCtx);

        play_.reset();

        play_ = std::make_unique<PlayState>();

        play_->onEnter(updateCtx);
      }
      break;
    }
  }
}

Engine::Engine() = default;

Engine::~Engine() {
  if (play_) {
    UpdateContext updateCtx = {*renderer_, *textures_, *fonts_};
    play_->onExit(updateCtx);
    play_.reset();
  }
  ui_.reset();
  textures_.reset();
  fonts_.reset();
  renderer_.reset();
  window_.reset();
  TTF_Quit();
  SDL_Quit();
}
