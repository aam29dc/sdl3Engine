#include "render/sprite.hpp"
#include "core/renderer.hpp"
#include "managers/texture.hpp"

void Sprite::render(const RenderContext &renderCtx, const Float2 &pos,
                    const Float2 &size) const {
  SDL_Texture *texture = renderCtx.textures.get(handle_);
  const SDL_FRect dst = {pos.x, pos.y, size.x, size.y};
  renderCtx.renderer.draw(texture, nullptr, &dst);
}
