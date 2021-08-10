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
 * \file window.h
 *
 * A blackhole library class for creating SDL windows
 */

#pragma once
#ifndef WINDOW_H
#define WINDOW_H


#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <stdio.h>
#include <sys/time.h>
#include <thread>
#include <ctime>
#include <memory>
#include "color.h"
#include "imageHolder.h"
#include "cameraHolder.h"

namespace blackhole {
namespace graphics {

struct floatXY {
  float x;
  float y;
};
  
class Window {
 private:
  bool init();
 private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Texture* preRenderer;

  SDL_Rect renderFrame;
  
  Color bg_color;
  int width;
  int height;
  const char* title;

  floatXY scale;
  int fps;

  float frameTime;
  
  std::list<CameraHolder> cameraQueue;
  std::list<ImageHolder> renderQueue;
  const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);
  double deltaTime = 0;
  
  std::thread renderThread;
  std::thread eventThread;
  bool running = false;
  bool closed = false;
  void (*_main)();
  
 public:
  Window(int width, int height, const char* title, SDL_Rect renderFrame);
  Window(int width, int height, const char* title, SDL_Rect renderFrame, Color bg);
  ~Window();

  void Render();

  void addCamera(Camera* cam);
  void removeCamera(Camera* cam);
  void addImage(ImageBase* image);
  void removeImage(ImageBase* image);
  
  int getWidth();
  int getHeight();
  
  SDL_Window* getWindow();
  SDL_Renderer* getRenderer();

  void setRenderFrame(int width, int height);

  void setScale(floatXY scale);
  floatXY getScale();

  void startMainLoop(void (*_main)(), int fps);
  void handleEvents();
  bool isClosed();

  float getTimeSinceLastFrame();
  void setFps(int fps);

  double getDeltaTime();
  bool keyDown(SDL_Scancode scancode);
  bool keyUp(SDL_Scancode scancode);
};
}}


#endif
