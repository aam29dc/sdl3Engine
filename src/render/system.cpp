#include "render/system.hpp"
#include "managers/entity.hpp"
#include "objects/entity.hpp"
#include <memory>

void RenderSystem::render(const EntityManager &entities,
                          const RenderContext &renderCtx,
                          const Camera &) const {
  for (const auto &e : entities.entities()) {
    if (e.entity->renderable()) {
      e.entity->renderable()->render(renderCtx, e.entity->pos(),
                                     e.entity->size());
    }
  }
}
