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
 * \file animation.h
 *
 * A blackhole library class for creating animation frames
 */

#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include "spritesheet.h"
#include "imageBase.h"
#include <iostream>
#include <stdio.h>

namespace blackhole {
namespace graphics {
class Animation : public ImageBase {
 private:
  SpriteSheet* images;
  int* frames;
  int num_frames;
  float speed;
  float time = 0;
 public:
  Animation(SpriteSheet* images, int frame, int* frames, int num_frames, float speed = 1);
  ~Animation();


  void setX(float x);
  void setY(float y);
  float getX();
  float getY();
  
  bool setFrame(int frame);
  int getFrame();

  void resetAnimation();
  void addTime(float time);
  
  SpriteSheet* getSpriteSheet();
  SDL_Texture* getTexture();

  
  SDL_Rect* getDestRect();
  SDL_Rect* getSrcRect();
  
};
}}
#endif
