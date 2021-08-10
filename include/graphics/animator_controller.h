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
 * \file animator_controller.h
 *
 * A blackhole library class for controlling animation frames
 */

#pragma once
#ifndef ANIMATOR_CONTROLLER_H
#define ANIMATOR_CONTROLLER_H

#include "animation.h"
#include "imageBase.h"
#include <iostream>
#include <stdio.h>

namespace blackhole {
namespace graphics {

struct animation_holder {
  const char* name;
  Animation animation;
};
  
class AnimatorController : public ImageBase {
 private:

  float x;
  float y;

  int array_length;
  animation_holder* animations;
  Animation* currentAnimation;
  const char* currentAnimationName;
 public:
  AnimatorController(animation_holder* animations, long int array_length);
  ~AnimatorController();

  void setAnimation(const char* animation);
  Animation* getAnimation();
  const char* getAnimationName();
  
  void setX(float x);
  void setY(float y);
  float getX();
  float getY();

  void addTime(float time);
  
  SDL_Texture* getTexture();
  SDL_Rect* getDestRect();
  SDL_Rect* getSrcRect();
};  
}}

#endif
