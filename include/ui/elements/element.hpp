#pragma once
#include "core/input.hpp"
#include "core/render_context.hpp"
#include "core/types.hpp"
#include "ui/colors.hpp"
#include <memory>
#include <string>
#include <vector>

struct RenderContext;

class UIElement {
protected:
  SDL_FRect rect_{0, 0, 0, 0};
  SDL_Color color_{Color::Light};
  SDL_Color outline_{Color::Gray};
  bool visible_{true};
  std::string name_{};

  inline static u32 count_ = 0;
  u32 id_{count_++};

  std::vector<std::unique_ptr<UIElement>> children_;

public:
  UIElement(const SDL_FRect &rect);
  virtual ~UIElement() = default;

  virtual void handleEvents(const Input &input);
  virtual void update(const float);
  virtual void render(const RenderContext &ctx) const;

  void add(std::unique_ptr<UIElement> ele);

  i32 id() const;
  const std::string &name() const;

  bool visible() const;
  void toggle();
};
