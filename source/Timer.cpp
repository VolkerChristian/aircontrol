#include "Timer.h"

#include <chrono>

uint64_t Timer::s_usecs_;

Timer::Timer(bool hilo) : hilo(hilo) {
    usecs_ = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() - Timer::s_usecs_;
}

Timer* Timer::timer(bool hilo) {
    return new Timer(hilo);
}

uint64_t Timer::start() {
    s_usecs_ = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    return s_usecs_;
}

uint64_t Timer::time() {
    return usecs_;
}

bool Timer::value() {
    return hilo;
}
