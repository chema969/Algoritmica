#include <cassert>
#include <ctime>
#include <cstdio>
#include <cstring> //Para usar memset
#include <iostream>
#include <stdint.h> 
#include "Tiempo.hpp"


uint64_t elapsed() const
    {
      assert (!_isStarted);
      uint64_t startT = (uint64_t)_start.tv_sec * 1000000LL + (uint64_t)_start.tv_nsec / 1000LL;
      uint64_t stopT = (uint64_t)_stop.tv_sec * 1000000LL + (uint64_t)_stop.tv_nsec / 1000LL;
      return stopT-startT;
    }
