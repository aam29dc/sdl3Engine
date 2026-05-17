#include "ui/menu/playScreen.hpp"
#include "ui/elements/element.hpp"
// #include "ui/elements/button.hpp"

PlayScreen::PlayScreen() {
  id_ = MenuID::PlayMenu;
  container_.add(
      std::make_unique<UIElement>(SDL_FRect{200., 200., 200., 200.}));
}
