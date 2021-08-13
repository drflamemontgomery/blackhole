#pragma once
#ifndef FILE_H
#define FILE_H

#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

namespace blackhole {

  std::string inline getLocalDir() {
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    std::string path(result, (count > 0) ? count : 0);
    return path.substr(0, path.find_last_of("/"));
  }
}

#endif
