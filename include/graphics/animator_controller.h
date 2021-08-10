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
