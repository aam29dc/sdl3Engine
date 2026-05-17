#pragma once
#include "core/input.hpp"
#include "core/renderer.hpp"
#include "core/types.hpp"
#include "ui/colors.hpp"
#include <string>

class UIElement {
protected:
  SDL_FRect rect_{0, 0, 0, 0};
  SDL_Color color_{Color::Light};
  SDL_Color outline_{Color::Gray};
  bool visible_{true};
  std::string name_{};

  inline static u32 count_ = 0;
  u32 id_{count_++};

public:
  UIElement(const SDL_FRect &rect);
  virtual ~UIElement() = default;

  virtual void handleEvents(const Input &input);
  virtual void update(const float);
  virtual void render(Renderer &renderer) const;

  i32 id() const;
  const std::string &name() const;

  bool visible() const;
  void toggle();
};
