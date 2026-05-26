#pragma once

#include <SDL3/SDL_rect.h>

struct UISpace {
  float width;
  float height;
};

/*struct UIContext {
  UISpace space;
  float scale;
};*/

enum class Anchor {
  TopLeft,
  TopCenter,
  TopRight,
  CenterLeft,
  Center,
  CenterRight,
  BottomLeft,
  BottomCenter,
  BottomRight
};

enum class UISizeMode {
  Uniform,
  Stretch
}; // , Fit = uniform and centered (black bars on both sides instead the right)

struct UITransform {
  SDL_FRect rect{0, 0, 0, 0};
  Anchor anchor = Anchor::TopLeft;
  UISizeMode sizeMode = UISizeMode::Stretch;
};

namespace UIConfig {
constexpr float DESIGN_WIDTH = 1440.0f;
constexpr float DESIGN_HEIGHT = 900.0f;
} // namespace UIConfig

SDL_FPoint getAnchorPoint(const Anchor anchor, const UISpace &space);

float getUniformScale(const UISpace &space);

float getScaleX(const UISpace &space);
float getScaleY(const UISpace &space);

SDL_FRect resolveRect(const UITransform &transform, const UISpace &space);
