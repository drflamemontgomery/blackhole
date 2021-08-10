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
 * \file camera.cpp
 *
 * A blackhole library class for viewing images
 */

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
    viewport = {0, 0, w, h};
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


  
  SDL_Rect* Camera::getViewport() {
    return &viewport;
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

  SDL_Texture* Camera::getCamTexture() {
    return texture;
  }
  
  void Camera::addTime(float time) {
    for(auto image = renderQueue.begin(); image != renderQueue.end(); ++image) {
      image->image->addTime(time);
    }
  }
}
