#include "render/rendersystem.hpp"
#include "core/camera.hpp"
#include "core/renderer.hpp"
#include "resource/texturemanager.hpp"
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
  for (const auto &layer : map.layers) {
    for (int y = 0; y < layer.height; y++) {
      for (int x = 0; x < layer.width; x++) {

        const u32 gid = layer.gids[y * layer.width + x];
        if (gid == 0)
          continue;

        const TileSet *tileset = nullptr;

        for (const auto &ts : map.tileSets) {
          if (gid >= ts.firstGid)
            tileset = &ts;
          else
            break;
        }

        if (!tileset)
          continue;

        u32 localId = gid - tileset->firstGid;

        int texX = localId % tileset->columns;
        int texY = localId / tileset->columns;

        SDL_FRect src = {(float)(texX * tileset->tileWidth),
                         (float)(texY * tileset->tileHeight),
                         (float)tileset->tileWidth, (float)tileset->tileHeight};

        SDL_FRect dst = {(float)x * tileset->tileWidth,
                         (float)y * tileset->tileHeight,
                         (float)tileset->tileWidth, (float)tileset->tileHeight};

        dst = camera.worldToScreen(dst);
        renderCtx.renderer.draw(renderCtx.textures.get(tileset->handle), &src,
                                &dst);
      }
    }
  }
}
