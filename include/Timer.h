#pragma once

#include <stdint.h>

class Timer
{
private:
    Timer(bool hilo);
    
public:
    static Timer* timer(bool hilo);
    uint64_t time();
    static uint64_t start();
    bool value();
    
private:
    uint64_t usecs_;
    static uint64_t s_usecs_;
    bool hilo;
};
