#include "ui/content/image.hpp"
#include "core/context/render.hpp"
#include "core/renderer.hpp"
#include "resource/texturemanager.hpp"
#include "ui/elements/element.hpp"

UIImageContent::UIImageContent(TextureHandle handle) : handle_(handle) {}

void UIImageContent::set(TextureHandle handle) {
  handle_ = handle;
  if (owner_)
    owner_->markDirty(Dirty::Render);
}

void UIImageContent::render(const SDL_FRect &rect,
                            const RenderContext &renderCtx) const {
  SDL_Texture *texture = renderCtx.textures.get(handle_);
  if (!texture)
    return;
  renderCtx.renderer.draw(texture, nullptr, &rect);
}

void UIImageContent::update(ResourceContext &, const float) {}
