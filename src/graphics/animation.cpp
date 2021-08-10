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
 * \file animation.cpp
 *
 * A blackhole library class for creating animation frames
 */

#include "graphics/animation.h"

namespace blackhole::graphics {

  Animation::Animation(SpriteSheet* images, int frame, int* frames, int num_frames, float speed)
  {
	this->images = images;
	images->setFrame(frame);
	this->frames = frames;
	this->num_frames = num_frames;
	printf("%d\n", num_frames);
	this->speed = speed;
  }

  Animation::~Animation() {

  }

  void Animation::setX(float x) {
	images->setX(x);
  }

  void Animation::setY(float y) {
	images->setY(y);
  }
  
  float Animation::getX() {
	return images->getX();
  }

  float Animation::getY() {
	return images->getY();
  }

  bool Animation::setFrame(int frame) {
	return images->setFrame(frame);
  }

  int Animation::getFrame() {
	return images->getFrame();
  }

  void Animation::resetAnimation() {
	this->time = 0;
  }
  
  void Animation::addTime(float time) {
	this->time += time;
    images->setFrame(frames[(int)(this->time / speed) % num_frames]);
  }

  SpriteSheet* Animation::getSpriteSheet() {
	return images;
  }

  SDL_Texture* Animation::getTexture() {
	return images->getTexture();
  }
  
  SDL_Rect* Animation::getSrcRect() {
	return images->getSrcRect();
  }

  SDL_Rect* Animation::getDestRect() {
	return images->getDestRect();
  }

}
