#pragma once
#include "ui/elements/container.hpp"
#include "ui/eventsink.hpp"
#include "ui/menu/id.hpp"

struct RenderContext;
class Renderer;

std::string menuIDtoString(const MenuID id);

class Menu {
protected:
  UIContainer root_;
  MenuID id_ = MenuID::Menu;

public:
  explicit Menu(const RenderContext &, const MenuID id = MenuID::Menu,
                const UITransform &transform = {{0, 0, 0, 0}, Anchor::TopLeft});
  virtual ~Menu() = default;

  void handleEvents(const Input &input, UIEventSink &sink);
  virtual void update(const UISpace &space, const float dt);
  virtual void render(const RenderContext &ctx) const;
  virtual void onEnter();
  virtual void onExit();
};
