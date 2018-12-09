#ifndef TIEMPO_HPP
#define TIEMPO_HPP


#include <cassert>
#include <ctime>
#include <cstdio>
#include <cstring> //Para usar memset
#include <iostream>
#include <stdint.h> // Para usar uint64_t

 
  class Clock
  {
  private:
    timespec _start;
    timespec _stop;
    bool _isStarted;
  public:
    Clock ()
    {
      memset(&_start,0,sizeof(timespec));
      memset(&_stop,0,sizeof(timespec));
      _isStarted=false;
    } 
    
 
    void start ()
    {      
      assert (!isStarted());
      clock_gettime (CLOCK_REALTIME, &_start);   
      _isStarted=true;
    }
     


    void restart ()
    {      
      clock_gettime (CLOCK_REALTIME, &_start);   
      _isStarted=true;
    }
   
    

    void stop ()
    {
      assert (_isStarted);
      clock_gettime (CLOCK_REALTIME, &_stop);   
      _isStarted=false;
    }


    bool isStarted() const
    {
      return _isStarted;
    }
   

 /*!\brief Return the elapsed time in mcs.*/
    uint64_t elapsed() const;
  };


#endif
