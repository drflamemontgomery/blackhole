#pragma once

#ifndef TILEMAP_H
#define TILEMAP_H

#include <tmxparser/Tmx.h>
#include "image.h"
#include "spritesheet.h"

namespace blackhole {
namespace graphics {  
class Tilemap {
 private:
  Tmx::Map* map;
  std::vector<Image*> tileLayers;
 public:
  Tilemap(const char* file, SDL_Renderer* renderer);
  ~Tilemap();

  Tmx::Map* getMap();
  Image* getTileLayerImage(int layer);
  const Tmx::TileLayer* getTileLayer(int layer);
  const Tmx::ObjectGroup* getObjectGroup(int layer);
  
};
}}

#endif
