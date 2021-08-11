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

  /**
   *  \brief The class for viewing images
   */
  class Camera : public ImageBase {
  private:
    float x;
    float y;
    SDL_Rect viewport;
    std::list<ImageHolder> renderQueue;

    SDL_Renderer* renderer;
  public:
    /**
     *  \brief The Constructor of Camera
     *
     *  \param renderer The renderer of the window
     *  \param w The width of the camera
     *  \param h The height of the camera
     *  \param x The x position of the camera
     *  \param y the y position of the camera
     */
    Camera(SDL_Renderer* renderer, int w, int h, float x = 0, float y = 0);
    ~Camera();

  
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
