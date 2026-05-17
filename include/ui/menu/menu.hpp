#pragma once
#include "ui/elements/container.hpp"
#include "ui/menu/id.hpp"
#include <iostream>
#include <queue>

class Renderer;
enum class UICmd;

std::string menuIDtoString(const MenuID id);

class Menu {
protected:
  UIContainer container_;
  MenuID id_ = MenuID::Menu;

public:
  Menu(const MenuID id = MenuID::Menu) : id_(id) {}
  virtual ~Menu() = default;

  std::queue<UICmd> handleEvents(const Input &input) {
    return container_.handleEvents(input);
  }
  void update(const float dt) { container_.update(dt); }
  void render(Renderer &renderer) const { container_.render(renderer); }
  void onEnter() { std::cout << menuIDtoString(id_) << " Enter.\n"; }
  void onExit() { std::cout << menuIDtoString(id_) << " Exit.\n"; }
};
