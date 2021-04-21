#include "graphics/animator_controller.h"

namespace blackhole::graphics {

  AnimatorController::AnimatorController(animation_holder* animations) {
	this->animations = animations;
	this->currentAnimation = animations[0].animation;
  }

  AnimatorController::~AnimatorController() {
  }

  void AnimatorController::setAnimation(const char* animation) {
	for(int i = 0; i < len(animations); i++) {
	  if(animations[i].name == animation) {
		currentAnimation = animations[i].animation;
	  }
	}
  }

  Animation AnimatorController::getAnimation() {
	return currentAnimation;
  }

  const char* AnimatorController::getAnimationName() {
	for(int i = 0; i < len(animations); i++) {
	  if(animations[i].animation == currentAnimation) {
	    return animations[i].name;
	  }
	}
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
	currentAnimation.addTime(time);
  }

  SDL_Texture* AnimatorController::getTexture() {
	return currentAnimation.getTexture();
  }

  SDL_RendererFlip AnimatorController::getRendererFlip() {
	return currentAnimation.getRendererFlip();
  }

  SDL_Rect* getDestRect() {
	destRect.x = round(this->x);
	destRect.y = round(this->y);
	return &destRect;
  }

  SDL_Rect* getSrcRect() {
	return currentAnimation.getSrcRect();
  }
  
}
