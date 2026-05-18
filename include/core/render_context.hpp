#pragma once

class Renderer;
class TextureManager;
class FontManager;

struct RenderContext {
  Renderer &renderer;
  TextureManager &textures;
  FontManager &fonts;
};
