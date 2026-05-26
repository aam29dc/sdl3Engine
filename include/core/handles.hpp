#pragma once
#include <cstdint>

struct TextureHandle {
  std::uint32_t id = 0; // id = index of a vector
  std::uint32_t generation = 0;
};

struct SoundHandle {
  std::uint32_t id = 0;
  std::uint32_t generation = 0;
};

struct FontHandle {
  std::uint32_t id = 0;
  std::uint32_t generation = 0;
};
