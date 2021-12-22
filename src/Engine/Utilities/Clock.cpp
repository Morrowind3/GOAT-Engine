#include "Clock.hpp"
#include "SDL_image.h"

using namespace Engine;

double Clock::lastRecordedUnmodifiedDeltaTime() const {
    return _lastRecordedUnmodifiedDeltaTimeInMs;
}

double Clock::getMaxFps() const {
    return 1000.0/_frameDelayInMs;
}

void Clock::setMaxFps(unsigned int maxFps) {
    _frameDelayInMs = 1000.0/(double)maxFps;
}

unsigned int Clock::getTicks() {
    #ifndef TEST_ENVIRONMENT
        return SDL_GetTicks();
    #else // If inside a testing environment, simulate a ticking clock instead of being dependent on SDL running
        return _currentFrameTickInMs+1;
    #endif
}

bool Clock::tickAndCheckIfNextFrameIsReady() {
    _currentFrameTickInMs = getTicks();
    _deltaTimeInMs = _currentFrameTickInMs - _previousFrameTickInMs;
    if (_deltaTimeInMs >= _frameDelayInMs) {
        _lastRecordedUnmodifiedDeltaTimeInMs = _deltaTimeInMs;
        _previousFrameTickInMs = _currentFrameTickInMs;
        return true;
    }
    return false;
}

[[maybe_unused]] double Clock::actualDeltaTime() const {
    return _deltaTimeInMs;
}

// Will be zero in paused state
double Clock::gameStateBasedDeltaTime() const {
    return (!_engineCalls.isPaused() * _deltaTimeInMs) * _engineCalls.speed();
}
