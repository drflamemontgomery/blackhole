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
 * \file imageBase.cpp
 *
 * A blackhole library abstract class for all image based classes
 */

#include "graphics/imageBase.h"
#include <SDL2/SDL_image.h>

namespace blackhole::graphics {
  void ImageBase::init(const char* file, SDL_Renderer* renderer) {

    if(file == NULL) {
      
      return;
    }
    
    SDL_Surface* surface;
    SDL_RWops* src = SDL_RWFromFile(file, "rb");
    if(src != NULL) {
      if(IMG_isICO(src) == 1) {
	surface = IMG_LoadICO_RW(src);
      }
      else if(IMG_isCUR(src) == 1) {
	surface = IMG_LoadCUR_RW(src);
      }
      else if(IMG_isBMP(src) == 1) {
	surface = IMG_LoadBMP_RW(src);
      }
      else if(IMG_isGIF(src) == 1) {
	surface = IMG_LoadGIF_RW(src);
      }
      else if(IMG_isJPG(src) == 1) {
	surface = IMG_LoadJPG_RW(src);
      }
      else if(IMG_isLBM(src) == 1) {
	surface = IMG_LoadLBM_RW(src);
      }
      else if(IMG_isPCX(src) == 1) {
	surface = IMG_LoadPCX_RW(src);
      }
      else if(IMG_isPNG(src) == 1) {
	surface = IMG_LoadPNG_RW(src);
      }
      else if(IMG_isPNM(src) == 1) {
	surface = IMG_LoadPNM_RW(src);
      }
      else if(IMG_isSVG(src) == 1) {
	surface = IMG_LoadSVG_RW(src);
      }
      else if(IMG_isTIF(src) == 1) {
	surface = IMG_LoadTIF_RW(src);
      }
      else if(IMG_isXCF(src) == 1) {
	surface = IMG_LoadXCF_RW(src);
      }
      else if(IMG_isXPM(src) == 1) {
	surface = IMG_LoadXPM_RW(src);
      }
      else if(IMG_isXV(src) == 1) {
	surface = IMG_LoadXV_RW(src);
      }
      else if(IMG_isWEBP(src) == 1) {
	surface = IMG_LoadWEBP_RW(src);
      }
      else {
	printf("Image Format Not Recognised\n");
	return;
      }
    }
    else {
      printf("File %s not found\n", file);
    }
	
    if(surface == NULL) {
      printf("Unable to Load Image\n");
    }

    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if(this->texture == NULL) {
      printf("Unable to Create Texture\n");
    }

    SDL_QueryTexture(this->texture, NULL, NULL, &destRect.w, &destRect.h);
  }

  void ImageBase::addTime(float time) {
  }

  void ImageBase::setFlipX(bool flipped) {
    if(flipped && (rendererFlip | SDL_FLIP_HORIZONTAL) != rendererFlip) {
      rendererFlip = static_cast<SDL_RendererFlip>(rendererFlip | SDL_FLIP_HORIZONTAL);
    }
    else if(!flipped && (rendererFlip | SDL_FLIP_HORIZONTAL) == rendererFlip) {
      rendererFlip = static_cast<SDL_RendererFlip>(rendererFlip ^ SDL_FLIP_HORIZONTAL);
    }
	
  }

  void ImageBase::setFlipY(bool flipped) {
    if(flipped && (rendererFlip | SDL_FLIP_VERTICAL) != rendererFlip) {
      rendererFlip = static_cast<SDL_RendererFlip>(rendererFlip | SDL_FLIP_VERTICAL);
    }
    else if(!flipped && (rendererFlip | SDL_FLIP_VERTICAL) == rendererFlip) {
      rendererFlip = static_cast<SDL_RendererFlip>(rendererFlip ^ SDL_FLIP_VERTICAL);;
    }
  }

  bool ImageBase::isFlippedX() {
    return (rendererFlip | SDL_FLIP_HORIZONTAL) == rendererFlip;
  }

  bool ImageBase::isFlippedY() {
    return (rendererFlip | SDL_FLIP_VERTICAL) == rendererFlip;
  }
  
  float ImageBase::getX() {
    return 0;
  }

  float ImageBase::getY () {
    return 0;
  }


  SDL_RendererFlip ImageBase::getRendererFlip() {
    return rendererFlip;
  }
  
  SDL_Rect* ImageBase::getDestRect() {
    return &destRect;
  }
  
  SDL_Rect* ImageBase::getSrcRect() {
    return NULL;
  }
  
  void ImageBase::setTexture(SDL_Texture* tex) {
    SDL_DestroyTexture(texture);
    texture = tex;
    SDL_QueryTexture(this->texture, NULL, NULL, &destRect.w, &destRect.h);
  }
  
  SDL_Texture* ImageBase::getTexture() {
    return texture;
  }


  void ImageBase::setLayer(int layer) {
    this->layer = layer;
  }

  int ImageBase::getLayer() {
    return layer;
  }
}
