#pragma once
#include "core/context/render.hpp"
#include "world/entitymanager.hpp"

class RenderSystem {
private:
public:
  void render(const EntityManager &entities, const RenderContext &renderCtx,
              const Camera &camera) const;
};
