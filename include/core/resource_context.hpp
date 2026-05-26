#pragma once

class TextureManager;
class FontManager;

struct ResourceContext {
  TextureManager &textures;
  FontManager &fonts;
};
