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
 * \file spritesheet.h
 *
 * A blackhole library class for using spritesheet images
 */

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
  SpriteSheet(const char* file, SDL_Renderer* renderer, float x = 0, float y = 0, int cols = 1, int rows = 1);
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
