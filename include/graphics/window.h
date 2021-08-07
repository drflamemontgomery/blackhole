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
  Color bg_color;
  int width;
  int height;
  const char* title;

  floatXY scale;
  
  std::list<ImageHolder> renderQueue;
  const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);
  double deltaTime = 0;
  
  std::thread renderThread;
  std::thread eventThread;
  bool running = false;
  bool closed = false;
  void (*_main)();
  
 public:
  Window(int width, int height, const char* title);
  Window(int width, int height, const char* title, Color bg);
  ~Window();

  void Render();
  
  void addImage(ImageBase* image);
  void removeImage(ImageBase* image);
  
  int getWidth();
  int getHeight();
  
  SDL_Window* getWindow();
  SDL_Renderer* getRenderer();

  void setScale(floatXY scale);
  floatXY getScale();

  void startMainLoop(void (*_main)());
  void handleEvents();
  bool isClosed();


  double getDeltaTime();
  bool keyDown(SDL_Scancode scancode);
  bool keyUp(SDL_Scancode scancode);
};
}}


#endif
