#include "ui/ui.hpp"
#include "core/render_context.hpp"
#include "ui/menu/mainScreen.hpp"
#include "ui/menu/playScreen.hpp"

UI::UI(RenderContext &ctx) { // we'd allocated all our menus seperately here,
                             // then only push
                             // menuScreen to stack

  playScreen_ = std::make_unique<PlayScreen>(ctx);
  stack_.push_back(MenuID::PlayMenu);
  menuScreen_ = std::make_unique<MainScreen>(ctx);

  stack_.push_back(MenuID::MainMenu);
  menuScreen_->onEnter();
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

void UI::update(const HUDData &hud, const float dt) {
  if (playState_) {
    playScreen_->update(dt);
    playScreen_->setHUDData(hud);
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

void UI::render(const RenderContext &ctx) const {
  if (playState_) {
    playScreen_->render(ctx);
  }
  switch (stack_.back()) {
  case MenuID::Menu:
  default:
    break;
  case MenuID::MainMenu:
    menuScreen_->render(ctx);
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
