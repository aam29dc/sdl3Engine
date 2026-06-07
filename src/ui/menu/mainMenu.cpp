#include "ui/menu/mainMenu.hpp"
#include "core/context/render.hpp"
#include "core/context/resource.hpp"
#include "managers/texture.hpp"
#include "ui/content/image.hpp"
#include "ui/content/text.hpp"
#include "ui/elements/button.hpp"
#include "ui/elements/element.hpp"

MainMenu::MainMenu(ResourceContext &resourceCtx)
    : Menu(resourceCtx, MenuID::Main) {

  UIElement &ele = root_.add(std::make_unique<UIElement>(
      UITransform{SDL_FRect{0, 0, 200, 200}, Anchor::TopLeft}));

  TextureHandle image = resourceCtx.textures.loadFromFile(
      resourceCtx.renderer, "assets/textures/image.png");

  ele.addContent(std::make_unique<UIImageContent>(image));
  ele.addContent(std::make_unique<UITextContent>(&ele, "xdc"));

  root_.add(std::make_unique<UIButton>(
      UITransform{SDL_FRect{200, 200, 100, 20}}, UICmd::Start));
}
