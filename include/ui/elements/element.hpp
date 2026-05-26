#pragma once
#include <memory>
#include <vector>

#include "core/types.hpp"
#include "ui/dirty.hpp"
#include "ui/layout.hpp"
#include "ui/style/style.hpp"
class Input;
class UIStyle;
class UIContent;
class UIEventSink;
struct UISpace;
class UIContainer;
struct RenderContext;

class UIElement {
protected:
  UITransform transform_{{0, 0, 0, 0}, Anchor::TopLeft};
  UIStyleParams styleParams_{false, false, false};
  SDL_FRect resolvedRect_{};
  std::unique_ptr<UIStyle> style_{};
  std::vector<std::unique_ptr<UIContent>> contents_;
  bool visible_ = true;
  Dirty dirty_ = Dirty::Layout;

  inline static u32 count_ = 1;
  u32 id_{count_++};

  UIContainer *parent_ = nullptr;

public:
  UIElement(const UITransform &transform = {{0, 0, 0, 0}, Anchor::TopLeft});
  virtual ~UIElement();

  virtual void handleEvents(const Input &input, UIEventSink &sink);
  virtual void update(const UISpace &space, const float dt);
  virtual void render(const RenderContext &ctx) const;
  void markDirty();

  void style(std::unique_ptr<UIStyle> style);
  void addContent(std::unique_ptr<UIContent> content);
  void parent(UIContainer *root);
  UITransform &transform();
  i32 id() const;

  bool visible() const;
  void visible(bool value);
};
