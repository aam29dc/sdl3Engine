#include "ui/ui.hpp"
#include "core/context/render.hpp"
#include "core/context/resource.hpp"
#include "ui/menu/mainMenu.hpp"
#include "ui/menu/playMenu.hpp"
#include <algorithm>

UI::UI(ResourceContext &resouceCtx) { // we'd allocated all our menus seperately
                                      // here, then only push menuMenu to stack

  playMenu_ = std::make_unique<PlayMenu>(resouceCtx);
  stack_.push_back(MenuID::Play);
  mainMenu_ = std::make_unique<MainMenu>(resouceCtx);

  stack_.push_back(MenuID::Main);
  mainMenu_->onEnter();
}

UI::~UI() {
  playMenu_->onExit();
  mainMenu_->onExit();
}

// push only unique menus on stack
void UI::push(const MenuID menu) {
  for (auto &s : stack_) {
    if (s == menu)
      return;
  }
  stack_.push_back(menu);
}

void UI::pop() {
  if (!stack_.empty()) {
    stack_.pop_back();
  }
}

// call corresponding menu function, we used a switch since we wont have many
void UI::handleEvents(const Input &input, UIEventSink &sink) {
  switch (stack_.back()) {
  case MenuID::Menu:
  default:
    return;
  case MenuID::Main:
    return mainMenu_->handleEvents(input, sink);
  case MenuID::Play:
    return playMenu_->handleEvents(input, sink);
  case MenuID::Pause:
  case MenuID::Audio:
  case MenuID::Controls:
  case MenuID::Settings:
  case MenuID::Video:
    return;
  }
}

void UI::update(ResourceContext &resourcCtx, const UISpace &space,
                const HUDData &hud, const float dt) {
  // update playMenu first
  if (std::find(stack_.begin(), stack_.end(), MenuID::Play) != stack_.end()) {
    playMenu_->update(resourcCtx, space, dt);
    playMenu_->setHUDData(hud);
  }

  switch (stack_.back()) {
  case MenuID::Menu:
  default:
    break;
  case MenuID::Main:
    mainMenu_->update(resourcCtx, space, dt);
    break;
  case MenuID::Play:
    // always update PlayMenu, above, thus do nothing here
    break;
  case MenuID::Pause:
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
  // render playMenu aka play HUD first
  if (std::find(stack_.begin(), stack_.end(), MenuID::Play) != stack_.end()) {
    playMenu_->render(ctx);
  }

  switch (stack_.back()) {
  case MenuID::Menu:
  default:
    break;
  case MenuID::Main:
    mainMenu_->render(ctx);
    break;
  case MenuID::Play:
    break; // we always render playState hud above
  case MenuID::Pause:
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
