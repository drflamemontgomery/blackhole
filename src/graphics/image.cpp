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
