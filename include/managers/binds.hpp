#pragma once
#include <SDL3/SDL_scancode.h>
#include <array>
#include <string>

class Binds {
private:
  struct Bind {
    std::string down;
    std::string up;
    bool bound = false;
  };
  std::array<Bind, SDL_SCANCODE_COUNT> binds_{};

public:
  Binds() = default;
  Binds(const Binds &) = delete;
  Binds &operator=(const Binds &) = delete;

  void bind(const SDL_Scancode key, const std::string &down,
            const std::string &up);

  const std::string *get(const SDL_Scancode key, const bool pressed) const;

  void unbind(const SDL_Scancode key);

  bool has(const SDL_Scancode key) const;
};
