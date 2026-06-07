#include "ui/menu/mainMenu.hpp"
#include "core/context/render.hpp"
#include "ui/content/text.hpp"
#include "ui/elements/button.hpp"
#include "ui/elements/element.hpp"

MainMenu::MainMenu(RenderContext &renderCtx) : Menu(renderCtx, MenuID::Main) {

  UIElement &ele = root_.add(std::make_unique<UIElement>(
      UITransform{SDL_FRect{0, 0, 100, 100}, Anchor::TopLeft}));

  ele.addContent(std::make_unique<UITextContent>(&ele, "hello"));

  root_.add(std::make_unique<UIButton>(
      UITransform{SDL_FRect{200, 200, 100, 20}}, UICmd::Start));
}
