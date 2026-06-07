#pragma once
#include "ui/hud.hpp"
#include "ui/menu/menu.hpp"

class PlayMenu : public Menu {
private:
  HUDData hud_{};

public:
  PlayMenu(ResourceContext &resourceCtx);
  void setHUDData(const HUDData &hud) { hud_ = hud; }
};
