#include "render/rendersystem.hpp"
#include "world/entity.hpp"
#include "world/entitymanager.hpp"
#include "world/map.hpp"
#include <memory>

void RenderSystem::renderEntities(const EntityManager &entities,
                                  const RenderContext &renderCtx,
                                  const Camera &) const {
  for (const auto &e : entities.entities()) {
    if (e.entity->renderable()) {
      e.entity->renderable()->render(renderCtx, e.entity->pos(),
                                     e.entity->size());
    }
  }
}

void RenderSystem::renderMap(const Map &map, const RenderContext &renderCtx,
                             const Camera &camera) const {
  map.
}
