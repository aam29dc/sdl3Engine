#pragma once

class Renderer;
class TextureManager;
class FontManager;

struct UpdateContext {
  Renderer &renderer;
  TextureManager &textures;
  FontManager &fonts;
};
