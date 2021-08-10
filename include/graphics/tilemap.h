/*
  MIT License

  Copyright (c) 2021 Ashton Warner

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
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
