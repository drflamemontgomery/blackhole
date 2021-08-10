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
 * \file image.cpp
 *
 * A blackhole library class for simple images
 */

#include "graphics/image.h"
#include <SDL2/SDL_image.h>

namespace blackhole::graphics {
  Image::Image(const char* file, SDL_Renderer* renderer, float x, float y) {
	
	init(file, renderer);

	this->x = x;
	this->y = y;
  }

  
  
  Image::~Image() {
  }

  
  void Image::setX(float x) {
	this->x = x;
  }

  void Image::setY(float y) {
	this->y = y;
  }
  
  float Image::getX() {
	return x;
  }

  float Image::getY() {
	return y;
  }


  SDL_Rect* Image::getDestRect() {
	destRect.x = round(x);
	destRect.y = round(y);
	return &destRect;
  }
  
}
