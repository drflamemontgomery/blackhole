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
 * \file spritesheet.h
 *
 * A blackhole library class for using spritesheet images
 */

#pragma once
#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H

#include "imageBase.h"

namespace blackhole {
namespace graphics {
class SpriteSheet : public ImageBase {
 private:
  float x;
  float y;

  int rows;
  int cols;
  int row_size;
  int col_size;

  int frames;
  int frame;
  
  SDL_Rect srcRect;
  
 public:
  SpriteSheet(const char* file, SDL_Renderer* renderer, float x = 0, float y = 0, int cols = 1, int rows = 1);
  ~SpriteSheet();

  bool setFrame(int frame);
  int getFrame();
  
  void setX(float x);
  void setY(float y);
  float getX();
  float getY();

  SDL_Rect* getDestRect();
  SDL_Rect* getSrcRect();
};  
}}

#endif
