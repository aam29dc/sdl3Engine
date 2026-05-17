#pragma once

#include <SDL3/SDL_rect.h>
#include <cstdint>

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

template <typename T> struct Vec2 {
  T x{};
  T y{};

  T *begin() { return &x; }
  T *end() { return &x + 2; }

  const T *begin() const { return &x; }
  const T *end() const { return &x + 2; }

  operator SDL_FPoint() const {
    SDL_FPoint p = {static_cast<float>(x), static_cast<float>(y)};
    return p;
  }

  operator SDL_Point() const {
    SDL_Point p = {static_cast<int>(x), static_cast<int>(y)};
    return p;
  }

  Vec2 operator-() const { return {-x, -y}; }

  Vec2 &operator+=(const Vec2 &r) {
    x += r.x;
    y += r.y;
    return *this;
  }

  Vec2 &operator-=(const Vec2 &r) {
    x -= r.x;
    y -= r.y;
    return *this;
  }

  Vec2 &operator*=(T s) {
    x *= s;
    y *= s;
    return *this;
  }

  Vec2 &operator/=(T s) {
    x /= s;
    y /= s;
    return *this;
  }
};

template <typename T> inline Vec2<T> operator+(Vec2<T> a, const Vec2<T> &b) {
  return a += b;
}

template <typename T> inline Vec2<T> operator-(Vec2<T> a, const Vec2<T> &b) {
  return a -= b;
}

template <typename T> inline Vec2<T> operator*(Vec2<T> a, T s) {
  return a *= s;
}

template <typename T> inline Vec2<T> operator*(T s, Vec2<T> a) {
  return a *= s;
}

template <typename T> inline Vec2<T> operator/(Vec2<T> a, T s) {
  return a /= s;
}

template <typename T>
inline bool operator==(const Vec2<T> &a, const Vec2<T> &b) {
  return a.x == b.x && a.y == b.y;
}

template <typename T>
inline bool operator!=(const Vec2<T> &a, const Vec2<T> &b) {
  return !(a == b);
}

using Float2 = Vec2<float>;
using Int2 = Vec2<i32>;
