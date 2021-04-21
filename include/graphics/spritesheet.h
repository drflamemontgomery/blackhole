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
  SpriteSheet(const char* file, SDL_Renderer* renderer, float x = 0, float y = 0, int rows = 1, int cols = 1);
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
