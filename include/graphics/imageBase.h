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

  char* source;
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
};
}}

#endif
