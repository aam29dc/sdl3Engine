#pragma once
#include "ui/hud.hpp"
#include "ui/menu/menu.hpp"

class PlayScreen : public Menu {
private:
  HUDData hud_{};

public:
  PlayScreen();
  void setHUDData(const HUDData &hud) { hud_ = hud; }
};
