#pragma once
#include "core/context/render.hpp"

class EntityManager;
struct Map;

class RenderSystem {
private:
public:
  void renderEntities(const EntityManager &entities,
                      const RenderContext &renderCtx,
                      const Camera &camera) const;

  void renderMap(const Map &map, const RenderContext &renderCtx,
                 const Camera &camera) const;
};
