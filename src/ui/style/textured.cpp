#include "ui/style/textured.hpp"
#include "core/context/render.hpp"
#include "core/renderer.hpp"
#include "resource/texturemanager.hpp"

UITexturedStyle::UITexturedStyle(TextureHandle handle) { handle_ = handle; }

void UITexturedStyle::render(const SDL_FRect &rect, const UIStyleParams &,
                             const RenderContext &renderCtx) const {

  SDL_Texture *texture = renderCtx.textures.get(handle_);
  if (!texture)
    return;
  renderCtx.renderer.draw(texture, nullptr, &rect);
}
