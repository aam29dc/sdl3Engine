#pragma once
#include "core/types.hpp"
#include <vector>

class UIElement;

enum class UICmd : u32 { None, Start, Disconnect, Reload };

struct UIEvent {
  UICmd cmd = UICmd::None;
  u32 elementID;
};

class UIEventSink {
private:
  std::vector<UIEvent> events_;

public:
  void push(const UIEvent &event) { events_.push_back(event); }

  const std::vector<UIEvent> &events() const { return events_; }

  void clear() { events_.clear(); }

  bool empty() const { return events_.empty(); }
};
