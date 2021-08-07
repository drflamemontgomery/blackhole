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
