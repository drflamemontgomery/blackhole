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
 * \file spritesheet.cpp
 *
 * A blackhole library class for using spritesheet images
 */

#include "graphics/spritesheet.h"

namespace blackhole::graphics {
  SpriteSheet::SpriteSheet(const char* file, SDL_Renderer* renderer,
						   float x,float y,
						   int cols, int rows
						   ) {
	init(file, renderer);
	this->x = x;
	this->y = y;
	
	this->rows = rows;
	this->cols = cols;

	SDL_QueryTexture(texture, NULL, NULL, &row_size, &col_size);
	
	this->row_size /= rows;
	this->col_size /= cols;

	this->frames = rows*cols;

	this->destRect.w = row_size;
	this->destRect.h = col_size;
	this->srcRect = {0, 0, row_size, col_size};
  }

  SpriteSheet::~SpriteSheet() {
  }

  bool SpriteSheet::setFrame(int frame) {
	frame %= frames;
	this->frame = frame;
	this->srcRect = {
	  frame%rows*row_size,
	  (int)frame/rows*col_size,
	  row_size,
	  col_size
	};

	return true;
  }

  int SpriteSheet::getFrame() {
	return frame;
  }
  
  
  void SpriteSheet::setX(float x) {
	this->x = x;
  }

  void SpriteSheet::setY(float y) {
	this->y = y;
  }

  float SpriteSheet::getX() {
    return x;
  }

  float SpriteSheet::getY() {
    return y;
  }

  SDL_Rect* SpriteSheet::getDestRect() {
	destRect.x = (int)x+0.5;
	destRect.y = (int)y+0.5;
	return &destRect;
  }
  
  SDL_Rect* SpriteSheet::getSrcRect() {
	return &srcRect;
  }
}
