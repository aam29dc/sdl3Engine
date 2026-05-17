#include "ui/menu/menu.hpp"

std::string menuIDtoString(const MenuID id) {
  switch (id) {
  case MenuID::Menu:
    return "Menu";
  case MenuID::MainMenu:
    return "MainMenu";
  case MenuID::PlayMenu:
    return "PlayMenu";
  case MenuID::PauseMenu:
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
