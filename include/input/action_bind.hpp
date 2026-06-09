#pragma once
#include "input/console.hpp"
#include "state/actionState.hpp"

inline void bindAction(Console &console, const std::string &name,
                       ActionState &state, bool ActionState::*member) {
  console.addAction(name, [&state, member](CommandContext &, bool pressed) {
    (state.*member) = pressed;
  });
}
