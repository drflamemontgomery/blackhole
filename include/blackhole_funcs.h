#pragma once
#ifndef BLACKHOLE_FUNCS_H
#define BLACKHOLE_FUNCS_H

#include <stdio.h>
#include <iostream>

#define round(a) ((int)(a+0.5))

template <typename T, std::size_t N>
std::size_t array_len(T(&)[N]);

#endif
