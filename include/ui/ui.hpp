#pragma once
#include <memory>
#include <queue>
#include <vector>

class Menu;
enum class MenuID;
enum class UICmd;
class MenuScreen;
class Renderer;
class Input;

class UI {
private:
  //  std::vector<std::unique_ptr<Menu>> screens_{};
  std::vector<MenuID> stack_{}; // is a stack ids, only ids of unique type can
                                // be pushed (no two of same type)
                                // stack_ should never contain playScreen_
  std::unique_ptr<Menu>
      menuScreen_{}; // preallocated menu, instead of std::vector allocated menu
                     // will just list every menu here
  //
  std::unique_ptr<Menu> playScreen_{};
  bool playState_{false};

public:
  UI(); // start off with menuScreen allocated
  ~UI();
  void push(const MenuID screen);
  void pop();

  std::queue<UICmd> handleEvents(const Input &input);
  void update(const float dt);
  void render(Renderer &renderer) const;
  void playState(const bool active) { playState_ = active; }
};
