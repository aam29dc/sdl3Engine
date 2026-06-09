#include "input/console.hpp"
#include "core/context/command.hpp"
#include "core/context/render.hpp"
#include "core/context/resource.hpp"
#include "core/engine.hpp"
#include "core/renderer.hpp"
#include "core/window.hpp"
#include "resource/fontmanager.hpp"
#include "resource/texturemanager.hpp"
#include "ui/layout.hpp"
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <core/context/command.hpp>
#include <sstream>
#include <string>

void Console::init(CommandContext &cmdCtx) {
  height_ = cmdCtx.engine.fonts().getLineHeight(size_);
}

Console::~Console() {
  clear();
  inputBufferDirty_ = true;
  historyDirty_ = true;
}

void Console::handleEvents(CommandContext &cmdCtx, const SDL_Event &e,
                           Window &window) {
  if (e.type == SDL_EVENT_KEY_DOWN && !e.key.repeat &&
      e.key.scancode == SDL_SCANCODE_GRAVE) {
    open_ = !open_;

    if (open_)
      SDL_StartTextInput(window.get());
    else
      SDL_StopTextInput(window.get());
  }

  if (!open_)
    return;

  if (e.type == SDL_EVENT_TEXT_INPUT) {
    inputBuffer_ += e.text.text;
    inputBufferDirty_ = true;
  }

  if (e.type == SDL_EVENT_KEY_DOWN &&
      e.key.scancode == SDL_SCANCODE_BACKSPACE && !inputBuffer_.empty()) {
    inputBuffer_.pop_back();
    inputBufferDirty_ = true;
  }

  if (e.type == SDL_EVENT_KEY_DOWN && e.key.scancode == SDL_SCANCODE_RETURN &&
      !inputBuffer_.empty()) {
    execute(cmdCtx, inputBuffer_);
    inputBuffer_.clear();
    inputBufferDirty_ = true;
  }
}

void Console::update(ResourceContext &resourceCtx, const UISpace &space,
                     const float) {
  if (inputBufferDirty_) {
    inputBufferDirty_ = false;

    if (inputBufferTexture_) {
      SDL_DestroyTexture(inputBufferTexture_);
      inputBufferTexture_ = nullptr;
    }

    SDL_Surface *surface =
        resourceCtx.fonts.getText(inputBuffer_, textColor_, size_, space.width);

    if (surface) {
      inputBufferTexture_ =
          SDL_CreateTextureFromSurface(resourceCtx.renderer.get(), surface);
      SDL_GetTextureSize(inputBufferTexture_, &width_, &height_);

      SDL_DestroySurface(surface);
    }
  }

  if (historyDirty_) {
    historyDirty_ = false;

    for (size_t i = historyLines_.size(); i < history_.size(); i++) {
      SDL_Surface *surface = resourceCtx.fonts.getText(history_[i], textColor_,
                                                       size_, space.width);
      HistoryLine line{};
      line.texture =
          SDL_CreateTextureFromSurface(resourceCtx.renderer.get(), surface);
      if (line.texture) {
        SDL_GetTextureSize(line.texture, &line.width, &line.height);
        historyLines_.push_back(line);
      }

      SDL_DestroySurface(surface);
    }
  }
}

void Console::render(RenderContext &renderCtx) const {
  if (!open_)
    return;

  // draw console bg
  SDL_Color color = {0, 0, 0, 127};
  renderCtx.renderer.setDrawColor(color);
  SDL_FRect rect = {0, 0, renderCtx.uiSpace.width,
                    renderCtx.uiSpace.height * 0.5f};
  renderCtx.renderer.drawFillRect(rect);

  SDL_FRect dst = {0, 0, 0, 0};
  float y = height_;

  // draw text inputBuffer line at bottom of console
  if (inputBufferTexture_ && !inputBuffer_.empty()) {
    dst = {0, renderCtx.uiSpace.height * 0.5f - height_, width_, height_};
    renderCtx.renderer.draw(inputBufferTexture_, nullptr, &dst);
  }

  // draw history lines in console
  if (!historyLines_.empty()) {
    for (size_t i = historyLines_.size(); i-- > 0;) {

      y += historyLines_[i].height;
      if (y >= renderCtx.uiSpace.height * 0.5f)
        break;
      dst = {0, renderCtx.uiSpace.height * 0.5f - y, historyLines_[i].width,
             historyLines_[i].height};
      renderCtx.renderer.draw(historyLines_[i].texture, nullptr, &dst);
    }
  }
}

void Console::addCommand(const std::string name, CommandFn fn) {
  if (commands_.find(name) == commands_.end())
    commands_[name] = fn;
  else
    print("addCommand error: " + name + " already exists.\n");
}

void Console::addAction(const std::string name, ActionFn fn) {
  if (actions_.find(name) == actions_.end())
    actions_[name] = fn;
  else
    print("addAction error: " + name + " already exists.\n");
}

void Console::print(const std::string &text) {
  history_.push_back(text);
  historyDirty_ = true;
}

void Console::clear() {
  for (auto &line : historyLines_) {
    SDL_DestroyTexture(line.texture);
  }
  historyLines_.clear();
  input_.clear();
  if (inputBufferTexture_)
    SDL_DestroyTexture(inputBufferTexture_);
  inputBufferTexture_ = nullptr;
  inputBuffer_.clear();
  history_.clear();
}

void Console::execute(CommandContext &cmdCtx, const std::string &line) {
  input_ = line;
  history_.push_back(line);
  historyDirty_ = true;

  Args args = tokenize(line);
  if (args.empty()) {
    input_.clear();
    return;
  }

  auto it = commands_.find(args[0]);
  if (it != commands_.end()) {
    it->second(cmdCtx, args);
  } else
    print("Unknown cmd " + args[0]);

  input_.clear();
}

Console::Args Console::tokenize(const std::string &line) {
  std::istringstream ss(line);
  std::string token;
  std::vector<std::string> tokens;

  while (ss >> token) {
    tokens.push_back(token);
  }

  return tokens;
}
