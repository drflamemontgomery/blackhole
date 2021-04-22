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
