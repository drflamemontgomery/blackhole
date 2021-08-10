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
 * \file animator_controller.cpp
 *
 * A blackhole library class for controlling animation frames
 */

#include "graphics/animator_controller.h"

namespace blackhole::graphics {

  AnimatorController::AnimatorController(animation_holder* animations, long int array_length){
	this->array_length = array_length;
	this->animations = animations;
	this->currentAnimation = &animations[0].animation;
	this->currentAnimationName = animations[0].name;
	this->destRect.w = currentAnimation->getDestRect()->w;
	this->destRect.h = currentAnimation->getDestRect()->h;
  }

  AnimatorController::~AnimatorController() {
  }

  void AnimatorController::setAnimation(const char* animation) {
	if(animation == currentAnimationName) {
	  return;
	}
	for(int i = 0; i < array_length; i++) {
	  if(animations[i].name == animation) {
		currentAnimation = &animations[i].animation;
		currentAnimationName = animations[i].name;
		destRect.w = currentAnimation->getDestRect()->w;
		destRect.h = currentAnimation->getDestRect()->h;

		currentAnimation->resetAnimation();
	  }
	}
  }

  Animation* AnimatorController::getAnimation() {
	return currentAnimation;
  }

  const char* AnimatorController::getAnimationName() {
	return currentAnimationName;
  }

  void AnimatorController::setX(float x) {
    this->x = x;
  }

  void AnimatorController::setY(float y) {
	this->y = y;
  }

  float AnimatorController::getX() {
	return x;
  }

  float AnimatorController::getY() {
	return y;
  }

  void AnimatorController::addTime(float time) {
	currentAnimation->addTime(time);
  }

  SDL_Texture* AnimatorController::getTexture() {
	return currentAnimation->getTexture();
  }

  SDL_Rect* AnimatorController::getDestRect() {
	destRect.x = round(this->x);
	destRect.y = round(this->y);
	return &destRect;
  }

  SDL_Rect* AnimatorController::getSrcRect() {
	return currentAnimation->getSrcRect();
  }
  
}
