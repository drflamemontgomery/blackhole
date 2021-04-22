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
