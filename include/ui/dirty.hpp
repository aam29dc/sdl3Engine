#pragma once
#include <cstdint>

enum class Dirty : uint8_t { None = 0, Layout = 1 << 0, Render = 1 << 1 };

inline Dirty operator|(Dirty a, Dirty b) {
  return static_cast<Dirty>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

inline Dirty operator&(Dirty a, Dirty b) {
  return static_cast<Dirty>(static_cast<uint8_t>(a) & static_cast<uint8_t>(b));
}

inline Dirty &operator|=(Dirty &a, Dirty b) {
  a = a | b;
  return a;
}

inline bool any(Dirty d) { return d != Dirty::None; }

inline bool hasFlag(Dirty value, Dirty flag) {
  return (value & flag) != Dirty::None;
}
