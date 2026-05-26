#include "ui/layout.hpp"
#include <algorithm>

SDL_FPoint getAnchorPoint(const Anchor anchor, const UISpace &space) {
  switch (anchor) {
  case Anchor::TopLeft:
    return {0, 0};
  case Anchor::TopCenter:
    return {space.width * 0.5f, 0};
  case Anchor::TopRight:
    return {space.width, 0};

  case Anchor::CenterLeft:
    return {0.0f, space.height * 0.5f};
  case Anchor::Center:
    return {space.width * 0.5f, space.height * 0.5f};
  case Anchor::CenterRight:
    return {space.width, space.height * 0.5f};

  case Anchor::BottomLeft:
    return {0.0f, space.height};
  case Anchor::BottomCenter:
    return {space.width * 0.5f, space.height};
  case Anchor::BottomRight:
    return {space.width, space.height};
  }
  return {0.f, 0.f};
}

float getUniformScale(const UISpace &space) {
  return std::min(space.width / UIConfig::DESIGN_WIDTH,
                  space.height / UIConfig::DESIGN_HEIGHT);
}

float getScaleX(const UISpace &space) {
  return space.width / UIConfig::DESIGN_WIDTH;
}
float getScaleY(const UISpace &space) {
  return space.height / UIConfig::DESIGN_HEIGHT;
}

SDL_FRect resolveRect(const UITransform &t, const UISpace &space) {
  const float scaleX = getScaleX(space);
  const float scaleY = getScaleY(space);
  const float uniform = std::min(scaleX, scaleY);

  SDL_FRect out{};

  switch (t.sizeMode) {

  case UISizeMode::Uniform: {
    const SDL_FPoint anchor = getAnchorPoint(t.anchor, space);

    out.x = anchor.x + t.rect.x * uniform;
    out.y = anchor.y + t.rect.y * uniform;
    out.w = t.rect.w * uniform;
    out.h = t.rect.h * uniform;
    break;
  }

  case UISizeMode::Stretch: {
    const SDL_FPoint anchor = getAnchorPoint(t.anchor, space);

    out.x = anchor.x + t.rect.x * scaleX;
    out.y = anchor.y + t.rect.y * scaleY;
    out.w = t.rect.w * scaleX;
    out.h = t.rect.h * scaleY;
    break;
  }
  }

  return out;
}
