#include <iostream>

#include "sys-volume-bridge.h"
#include "sys-volume.hpp"



int LIB_setSystemVolume(float newVolume)
{
  int result = setSystemVolume(newVolume);
  
  std::cout << "[c++ bridge] LIB_setSystemVolume(" << newVolume << ") = " << result << std::endl;

  return result;
}

float LIB_getSystemVolume()
{
  float volume = getSystemVolume();

  std::cout << "[c++ bridge] LIB_getSystemVolume(" << volume << ")" << std::endl;

  return volume;
}