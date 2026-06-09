#include "input/binds.hpp"

void Binds::bind(const SDL_Scancode key, const std::string &down,
                 const std::string &up) {
  binds_[key] = {down, up, true};
}

const std::string *Binds::get(const SDL_Scancode key,
                              const bool pressed) const {
  const Bind &b = binds_[key];
  if (!b.bound)
    return nullptr;
  return pressed ? &b.down : &b.up;
}

void Binds::unbind(const SDL_Scancode key) { binds_[key] = {}; }

bool Binds::has(const SDL_Scancode key) const { return binds_[key].bound; }
