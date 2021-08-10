/*
  Copyright (C) 2021, Ashton Warner
  All rights reserved.
  
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/**
 * \file tilemap.h
 *
 * A blackhole library class for turning tilemaps into images
 */

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
  Image** tileLayers;
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
