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
 * \file imageBase.h
 *
 * A blackhole library abstract class for all image based classes
 */

#pragma once
#ifndef IMAGE_BASE_H
#define IMAGE_BASE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../blackhole_funcs.h"


namespace blackhole {
namespace graphics {  
class ImageBase {
 protected:
  SDL_RendererFlip rendererFlip = SDL_FLIP_NONE;

  int layer = 0;
  
  SDL_Rect destRect;
  SDL_Texture* texture;
  void init(const char* file, SDL_Renderer* renderer);
 public:
  
  virtual float getX();
  virtual float getY();

  virtual void addTime(float time);
  virtual void setFlipX(bool flipped);
  virtual void setFlipY(bool flipped);

  virtual void setTexture(SDL_Texture* tex);
  
  virtual bool isFlippedX();
  virtual bool isFlippedY();
  
  virtual SDL_RendererFlip getRendererFlip();
  virtual SDL_Rect* getDestRect();
  virtual SDL_Rect* getSrcRect();
  virtual SDL_Texture* getTexture();

  virtual void setLayer(int layer);
  virtual int getLayer();
};
}}

#endif
