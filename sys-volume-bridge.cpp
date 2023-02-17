#include <iostream>

#include "sys-volume-bridge.h"
#include "sys-volume.hpp"

int LIB_setSystemVolume(float newVolume)
{
  int result = setSystemVolume(newVolume);
  return result;
}

float LIB_getSystemVolume()
{
  float volume = getSystemVolume();
  return volume;
}