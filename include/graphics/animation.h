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
  Animation(SpriteSheet* images, int frame, int* frames, float speed = 1);
  ~Animation();


  void setX(float x);
  void setY(float y);
  float getX();
  float getY();
  
  bool setFrame(int frame);
  int getFrame();

  void addTime(float time);
  
  SpriteSheet* getSpriteSheet();
  SDL_Texture* getTexture();

  
  SDL_RendererFlip getRendererFlip();
  SDL_Rect* getDestRect();
  SDL_Rect* getSrcRect();
  
};
}}
#endif
