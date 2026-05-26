#pragma once

class Renderer;
class TextureManager;
class FontManager;
struct UISpace;
class Camera;

struct RenderContext {
  Renderer &renderer;

  const TextureManager &textures;
  const FontManager &fonts;
  const UISpace &uiSpace;
};
