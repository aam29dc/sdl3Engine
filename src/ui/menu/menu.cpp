#include "ui/menu/menu.hpp"

std::string menuIDtoString(const MenuID id) {
  switch (id) {
  case MenuID::Menu:
    return "Menu";
  case MenuID::Main:
    return "MainMenu";
  case MenuID::Play:
    return "PlayMenu";
  case MenuID::Pause:
    return "PauseMenu";
  case MenuID::Settings:
    return "Settings";
  case MenuID::Audio:
    return "Audio";
  case MenuID::Video:
    return "Video";
  case MenuID::Controls:
    return "Controls";
  }
  return "Unknown";
}

Menu::Menu(const RenderContext &, const MenuID id, const UITransform &transform)
    : root_(transform), id_(id) {}

void Menu::handleEvents(const Input &input, const UISpace &space,
                        UIEventSink &sink) {
  return root_.handleEvents(input, space, sink);
}

void Menu::update(const float dt) { root_.update(dt); }

void Menu::render(const RenderContext &ctx) const { root_.render(ctx); }

void Menu::onEnter() {}

void Menu::onExit() {}
