#include <iostream>

#include "tmp-bridge.h"
#include "tmp.hpp"

int LIB_getMyInt() {
  int x = getMyInt();
  std::cout << "[c++ bridge] LIB_FooValue(" << x << ")" << std::endl;
  return x;
}