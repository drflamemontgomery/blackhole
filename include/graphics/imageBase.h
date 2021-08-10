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
