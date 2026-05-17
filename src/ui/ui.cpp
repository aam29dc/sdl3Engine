#include "ui/ui.hpp"
#include "core/renderer.hpp"
#include "ui/menu/mainScreen.hpp"
#include "ui/menu/playScreen.hpp"

UI::UI() { // we'd allocated all our menus seperately here, then only push
           // menuScreen to stack

  playScreen_ = std::make_unique<PlayScreen>();
  stack_.push_back(MenuID::PlayMenu);
  menuScreen_ = std::make_unique<MainScreen>();

  stack_.push_back(MenuID::MainMenu);
}

UI::~UI() {
  if (playState_)
    playScreen_->onExit();
  menuScreen_->onExit();
}

// push only unique screens on stack
void UI::push(const MenuID screen) {
  for (auto &s : stack_) {
    if (s == screen)
      return;
  }
  stack_.push_back(screen);
}

void UI::pop() {
  if (!stack_.empty()) {
    stack_.pop_back();
  }
}

// call corresponding screen function, we used a switch since we wont have many
std::queue<UICmd> UI::handleEvents(const Input &input) {
  switch (stack_.back()) {
  case MenuID::Menu:
  default:
    return {};
  case MenuID::MainMenu:
    return menuScreen_->handleEvents(input);
  case MenuID::PlayMenu:
    return playScreen_->handleEvents(input);
  case MenuID::PauseMenu:
  case MenuID::Audio:
  case MenuID::Controls:
  case MenuID::Settings:
  case MenuID::Video:
    return {};
  }
}

void UI::update(const float dt) {
  if (playState_) {
    playScreen_->update(dt);
  }
  switch (stack_.back()) {
  case MenuID::Menu:
  default:
    break;
  case MenuID::MainMenu:
    menuScreen_->update(dt);
    break;
  case MenuID::PlayMenu:
    // always update PlayScreen
    break;
  case MenuID::PauseMenu:
    break;
  case MenuID::Audio:
    break;
  case MenuID::Controls:
    break;
  case MenuID::Settings:
    break;
  case MenuID::Video:
    break;
  }
}

void UI::render(Renderer &renderer) const {
  if (playState_) {
    playScreen_->render(renderer);
  }
  switch (stack_.back()) {
  case MenuID::Menu:
  default:
    break;
  case MenuID::MainMenu:
    menuScreen_->render(renderer);
    break;
  case MenuID::PlayMenu:
    break; // we always render playState hud above
  case MenuID::PauseMenu:
    break;
  case MenuID::Audio:
    break;
  case MenuID::Controls:
    break;
  case MenuID::Settings:
    break;
  case MenuID::Video:
    break;
  }
}
