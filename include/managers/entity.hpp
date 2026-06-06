#pragma once
#include "core/handles.hpp"
#include "objects/entity.hpp"
#include <memory>
#include <vector>

class EntityManager {
public:
  struct Slot {
    std::unique_ptr<Entity> entity;
    u32 generation = 1;
  };
  void update(const float dt);
  void removeDead();
  void clear();

  EntityHandle spawn(std::unique_ptr<Entity> entity);

  std::vector<Slot> &entities();
  const std::vector<Slot> &entities() const;

  Entity &entity(const EntityHandle handle);
  const Entity &entity(const EntityHandle handle) const;

private:
  std::vector<Slot> entities_;
  std::vector<u32> freeSlots_;
};
