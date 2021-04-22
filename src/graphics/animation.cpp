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
