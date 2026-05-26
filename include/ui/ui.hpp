#pragma once
#include <memory>
#include <vector>

#include "ui/menu/id.hpp"

class Menu;
class MainMenu;
class PauseMenu;
class SettingsMenu;
class PlayMenu;

class Input;
class UIEventSink;

struct RenderContext;
struct UISpace;
struct HUDData;

class UI {
private:
  std::unique_ptr<MainMenu> mainMenu_;
  // std::unique_ptr<PauseMenu> pauseMenu_;
  // std::unique_ptr<SettingsMenu> settingsMenu_;
  std::unique_ptr<PlayMenu> playMenu_;

  std::vector<MenuID> stack_;

public:
  UI(RenderContext &ctx);
  ~UI();

  void push(MenuID id);
  void pop();

  void handleEvents(const Input &, const UISpace &, UIEventSink &);
  void update(const HUDData &, float dt);
  void render(const RenderContext &) const;

private:
  Menu *get(MenuID id);
  const Menu *get(MenuID id) const;
};
