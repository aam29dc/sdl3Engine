#include "ui/menu/playScreen.hpp"
#include "core/render_context.hpp"
#include "ui/elements/button.hpp"
#include "ui/elements/label.hpp"
#include <memory>

PlayScreen::PlayScreen(RenderContext &ctx) : Menu(ctx, MenuID::PlayMenu) {
  container_.add(std::make_unique<UIButton>(SDL_FRect{200., 200., 200., 200.},
                                            UICmd::Disconnect));
  container_.add(std::make_unique<UILabel>(ctx, SDL_FRect{100, 100, 100, 100},
                                           "hello world."));
}
