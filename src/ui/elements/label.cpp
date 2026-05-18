#include "ui/elements/label.hpp"
#include "core/render_context.hpp"
#include "core/renderer.hpp"
#include "managers/font.hpp"
#include "managers/texture.hpp"

UILabel::UILabel(RenderContext &ctx, const SDL_FRect &rect,
                 const std::string &text)
    : UIElement(rect), text_(text) {
  SDL_Texture *texture =
      ctx.fonts.getText(&ctx.renderer, text, FontManager::FontSize::Medium);
  handle_ = ctx.textures.load(texture);
}

void UILabel::update(const float) {}
void UILabel::render(const RenderContext &ctx) const {
  ctx.renderer.draw(ctx.textures.get(handle_.id), nullptr, &rect_);
}

void UILabel::text(const RenderContext &, const std::string &) {
  //  ctx.fonts.getText(ctx.renderer, newText
}

/*class TextureManager {
private:
  std::unordered_map<u32, SDL_Texture *> textures_;
  u32 nextID_ = 1;

public:
  TextureManager() = default;
  ~TextureManager() = default;

  TextureManager(const TextureManager &) = delete;
  TextureManager &operator=(const TextureManager &) = delete;
  TextureManager(TextureManager &&) = delete;
  TextureManager &operator=(TextureManager &&) = delete;

  TextureHandle load(Renderer &renderer, const std::string &imgFile);
  TextureHandle load(SDL_Texture *texture);

  bool remove(u32 id);
  void clear();
  SDL_Texture *get(u32 id) const;
};*/
