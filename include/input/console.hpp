#pragma once
#include "resource/fontmanager.hpp"
#include <SDL3/SDL_events.h>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

class Input;
class Window;
struct ResourceContext;
struct RenderContext;
struct CommandContext;
struct SDL_Texture;
struct UISpace;

class Console {
public:
  using Args = std::vector<std::string>;
  using CommandFn = std::function<void(CommandContext &, const Args &)>;
  // using CommandFn = void(*)(CommandContext&, const Args&);
private:
  struct HistoryLine {
    SDL_Texture *texture;
    float height;
    float width;
  };
  std::string input_{}; // input entered into the console
  std::string inputBuffer_{};
  SDL_Texture *inputBufferTexture_{nullptr};
  float height_ = 0.0f;
  float width_ = 0.0f;
  FontManager::FontSize size_{FontManager::FontSize::Medium};
  bool inputBufferDirty_{true};

  std::vector<std::string> history_{};      // full input history log
  std::vector<HistoryLine> historyLines_{}; // textures vector with a max size
  bool historyDirty_{false};

  std::unordered_map<std::string, CommandFn> commands_{};

  static Args tokenize(const std::string &line);
  bool open_ = false;

  SDL_Color textColor_{0, 0, 0, 255};

public:
  void init(CommandContext &cmdCtx);
  ~Console();

  void handleEvents(CommandContext &cmdCtx, const SDL_Event &e, Window &window);
  void update(ResourceContext &resourceCtx, const UISpace &space,
              const float dt);
  void render(RenderContext &renderCtx) const;

  void execute(CommandContext &cmdCtx, const std::string &line);
  void addCommand(std::string name, CommandFn fn);
  void print(const std::string &text);
  void clear();
};
