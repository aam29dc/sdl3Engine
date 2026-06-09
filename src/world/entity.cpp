#include "world/entity.hpp"
#include "render/renderable.hpp"
#include <memory>

void Entity::update(const float) {}
bool Entity::alive() const { return alive_; }
void Entity::destroy() { alive_ = false; }

Float2 &Entity::pos() { return pos_; }
const Float2 &Entity::pos() const { return pos_; }

Float2 &Entity::size() { return size_; }
const Float2 &Entity::size() const { return size_; }

SDL_FRect Entity::rect() const { return {pos_.x, pos_.y, size_.x, size_.y}; }

const Renderable *Entity::renderable() const { return renderable_.get(); }

void Entity::renderable(std::unique_ptr<Renderable> renderable) {
  renderable_ = std::move(renderable);
}
