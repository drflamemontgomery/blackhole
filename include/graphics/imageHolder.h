#pragma once
#ifndef IMAGE_HOLDER_H
#define IMAGE_HOLDER_H

#include "imageBase.h"
#include "image.h"
#include "spritesheet.h"

namespace blackhole {
namespace graphics {

struct ImageHolder {
  ImageBase* image;
};
}}

#endif
