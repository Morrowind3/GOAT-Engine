#include "EngineCalls.hpp"

using namespace Engine;

bool EngineCalls::isPaused() const {
    return _paused;
}

void EngineCalls::pause(bool shouldBePaused) {
    _paused = shouldBePaused;
}

double EngineCalls::speed() const {
    return _speed;
}

void EngineCalls::modifySpeed(double speed) {
    _speed = speed;
}

bool EngineCalls::quitEventQueued() const {
    return _quit;
}

void EngineCalls::queueQuitEvent() {
    _quit = true;
}
