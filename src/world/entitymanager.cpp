#include "world/entitymanager.hpp"
#include "core/handles.hpp"
#include <memory>

void EntityManager::update(const float dt) {
  for (auto &slot : entities_) {
    if (slot.entity)
      slot.entity->update(dt);
  }
}

void EntityManager::removeDead() {
  for (u32 i = 0; i < entities_.size(); i++) {
    auto &slot = entities_[i];
    if (slot.entity && !slot.entity->alive()) {
      slot.entity.reset();
      ++slot.generation;
      freeSlots_.push_back(i);
    }
  }
}

void EntityManager::clear() { entities_.clear(); }

EntityHandle EntityManager::spawn(std::unique_ptr<Entity> entity) {
  if (!entity)
    return {0};

  u32 index = 0;

  if (!freeSlots_.empty()) {
    index = freeSlots_.back();
    freeSlots_.pop_back();
    entities_[index].generation++;
    entities_[index].entity = std::move(entity);
  } else {
    index = entities_.size();
    entities_.push_back({std::move(entity)});
  }
  return {index, entities_[index].generation};
}

std::vector<EntityManager::Slot> &EntityManager::entities() {
  return entities_;
}

const std::vector<EntityManager::Slot> &EntityManager::entities() const {
  return entities_;
}

Entity &EntityManager::entity(const EntityHandle handle) {
  return *entities_[handle.id].entity;
}

const Entity &EntityManager::entity(const EntityHandle handle) const {
  return *entities_[handle.id].entity;
}
