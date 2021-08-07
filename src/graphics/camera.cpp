#include "graphics/camera.h"

namespace blackhole::graphics {

  extern bool compare_position(const ImageHolder& first, const ImageHolder& second);
  
  Camera::Camera(SDL_Renderer* renderer, int w, int h, float x, float y) {
    this->renderer = renderer;
    this->texture = SDL_CreateTexture(renderer,
				      SDL_PIXELFORMAT_RGBX8888,
				      SDL_TEXTUREACCESS_TARGET,
				      w,
				      h);
    this->x = x;
    this->y = y;

    destRect = {(int)x, (int)y, w, h};
  }

  Camera::~Camera() {
    SDL_DestroyTexture(texture);
  }

  void Camera::setX(float x) {
    this->x = x;
  }

  void Camera::setY(float y) {
    this->y = y;
  }

  void Camera::addImage(ImageBase* image) {
    ImageHolder imageHolder = {
      image
    };
    renderQueue.push_back(imageHolder);
    renderQueue.sort(compare_position);
  }

  void Camera::removeImage(ImageBase* image) {
    renderQueue.remove_if([image](const ImageHolder& value) {return value.image == image;});
  }

  SDL_Texture* Camera::getTexture() {
    SDL_SetRenderTarget(renderer, texture);
    SDL_RenderClear(renderer);

    for(auto image = renderQueue.begin(); image != renderQueue.end(); ++image) {
      SDL_RenderCopyEx(renderer, image->image->getTexture(), image->image->getSrcRect(),image->image->getDestRect(), 0, NULL, image->image->getRendererFlip());
    }
    
    
    SDL_SetRenderTarget(renderer, NULL);

    return texture;
  }

  void Camera::addTime(float time) {
    for(auto image = renderQueue.begin(); image != renderQueue.end(); ++image) {
      image->image->addTime(time);
    }
  }
}
