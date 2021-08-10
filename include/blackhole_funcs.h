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
 * \file blackhole_funcs.h
 *
 * A blackhole library for universal functions
 */

#pragma once
#ifndef BLACKHOLE_FUNCS_H
#define BLACKHOLE_FUNCS_H

#include <stdio.h>
#include <iostream>

static inline int round(int a) {
  return (int)(a+0.5);
}

#endif
