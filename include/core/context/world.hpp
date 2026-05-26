#pragma once

class Renderer;
class TextureManager;
class FontManager;
class Camera;

struct WorldContext {
  Renderer &renderer;

  const TextureManager &textures;
  const FontManager &fonts;
  const Camera &camera;
};
