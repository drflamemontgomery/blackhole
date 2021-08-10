/*
  MIT License

  Copyright (c) 2021 Ashton Warner

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
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
