#include "ui/menu/mainScreen.hpp"
#include "ui/elements/button.hpp"

MainScreen::MainScreen() {
  id_ = MenuID::MainMenu;
  container_.add(std::make_unique<UIButton>(SDL_FRect{400., 400., 400., 400.},
                                            UICmd::Start));
}
