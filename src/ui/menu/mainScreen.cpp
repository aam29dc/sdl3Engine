#include "ui/menu/mainScreen.hpp"
#include "core/render_context.hpp"
#include "ui/elements/button.hpp"

MainScreen::MainScreen(RenderContext &ctx) : Menu(ctx, MenuID::MainMenu) {
  container_.add(std::make_unique<UIButton>(SDL_FRect{400., 400., 400., 400.},
                                            UICmd::Start));
}
