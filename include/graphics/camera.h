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
 * \file camera.h
 *
 * A blackhole library class for viewing images
 */

#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "imageBase.h"
#include "imageHolder.h"
#include <iostream>
#include <list>

namespace blackhole {
namespace graphics {
class Camera : public ImageBase {
 private:
  float x;
  float y;
  SDL_Rect viewport;
  std::list<ImageHolder> renderQueue;

  SDL_Renderer* renderer;
 public:
  Camera(SDL_Renderer* renderer, int w, int h, float x = 0, float y = 0);
  ~Camera();

  void addTime(float time);
  
  void setX(float x);
  void setY(float y);
  
  void addImage(ImageBase* image);
  void removeImage(ImageBase* tex);

  SDL_Rect* getViewport();
  SDL_Texture* getCamTexture();
  SDL_Texture* getTexture();
};
}}

#endif
