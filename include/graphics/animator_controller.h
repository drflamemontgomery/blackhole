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
 * \file animator_controller.h
 *
 * A blackhole library class for controlling animation frames
 */

#pragma once
#ifndef ANIMATOR_CONTROLLER_H
#define ANIMATOR_CONTROLLER_H

#include "animation.h"
#include "imageBase.h"
#include <iostream>
#include <stdio.h>

namespace blackhole {
namespace graphics {

  /**
   *  \brief Information of animation
   */
  struct animation_holder {
    const char* name;     /**< The name of the animation */
    Animation animation;  /**< The animation from spritesheets */
  };

  /**
   *  \brief The class for holding and controlling Animations
   */
  class AnimatorController : public ImageBase {
  private:

    float x;
    float y;

    int array_length;
    animation_holder* animations;
    Animation* currentAnimation;
    const char* currentAnimationName;
  public:

    /**
     *  \brief The constructor of the AnimatorController
     *
     *  \param animations The array of animations
     *  \param array_length The amount of animations
     */
    AnimatorController(animation_holder* animations, long int array_length);
    ~AnimatorController();

    /**
     *  \brief Set the animation to be displayed
     *
     *  \param animation The name of the animation to display eg. running
     *
     *  \sa getAnimation()
     *  \sa getAnimationName()
     */
    void setAnimation(const char* animation);

    /**
     *  \brief Get the animation that is being displayed
     *
     *  \return Animation* of the animation that is being displayed 
     *
     *  \sa setAnimation()
     *  \sa getAnimationName()
     */
    Animation* getAnimation();

    /**
     *  \brief Get the name of the animation that is being displayed
     *
     *  \return const char* name of the animation being displayed eg. running
     *  \sa getAnimation()
     *  \sa setAnimation()
     */
    const char* getAnimationName();



    /**
     *  \brief Set the x position of the animation being displayed
     *
     *  \param x The x position you want the sprite to render on
     *
     *  \sa getX()
     *  \sa getY()
     *  \sa setY()
     */
    void setX(float x);

    /**
     *  \brief Set the y position of the animation being displayed
     *
     *  \param y The y position you want the sprite to render on
     *
     *  \sa getY()
     *  \sa getX()
     *  \sa setX()
     */
    void setY(float y);

    /**
     *  \brief Get the x position of the animation being displayed
     *
     *  \sa setX()
     *  \sa setY()
     *  \sa getY()
     */
    float getX();

    /**
     *  \brief Get the y position of the animation being displayed
     *
     *  \sa setY()
     *  \sa setX()
     *  \sa getX()
     */
    float getY();



    /**
     *  \brief add the amount of time passed so that the animation
     *         can update.
     *
     *  \param time The amount of time passed in the frame
     */
    void addTime(float time);


    
    /**
     *  \brief Get a pointer to the animation texture
     *
     *  \return SDL_Texture* of the animation for rendering
     */
    SDL_Texture* getTexture();


    
    /**
     *  \brief Get a pointer to the destination rect used for positioning
     *         with the renderer
     *
     *  \return SDL_Rect* destRect of animation
     */
    SDL_Rect* getDestRect();

    /**
     *  \brief Get a pointer to the source rect used for getting the frame
     *         of the animation
     *
     *  \return SDL_Rect* srcRect of animation
     */
    SDL_Rect* getSrcRect();
  };  
}}

#endif
