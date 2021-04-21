#pragma once
#ifndef IMAGE_H
#define IMAGE_H

#include "imageBase.h"

namespace blackhole {
namespace graphics {  
class Image : public ImageBase {
private:
  float x;
  float y;
public:
  Image(const char* file, SDL_Renderer* renderer, float x = 0, float y = 0);
  ~Image();
  
  void setX(float x);
  void setY(float y);
  float getX();
  float getY();

  SDL_Rect* getDestRect();
};
}}

#endif
