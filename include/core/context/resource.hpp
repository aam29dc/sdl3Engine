#pragma once

class TextureManager;
class FontManager;
class Renderer;

struct ResourceContext {
  TextureManager &textures;
  FontManager &fonts;
  Renderer &renderer;
};
