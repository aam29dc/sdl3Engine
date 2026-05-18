#pragma once
#include "ui/hud.hpp"
#include "ui/menu/menu.hpp"

struct RenderContext;

class PlayScreen : public Menu {
private:
  HUDData hud_{};

public:
  PlayScreen(RenderContext &ctx);
  void setHUDData(const HUDData &hud) { hud_ = hud; }
};
