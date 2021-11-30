#include "SpeedScript.hpp"

SpeedScript::SpeedScript(AudioSource& speedUpSound, AudioSource& slowDownSound, AudioSource& resetSound,
                         AudioSource& impossibleToAdjustSound, bool active): Script(active),
    _speedUpSound{speedUpSound}, _slowDownSound{slowDownSound}, _resetSound{resetSound}, _impossibleToAdjustSound{impossibleToAdjustSound} {
}

void SpeedScript::onUpdate(double deltaTime) {
    if (_input.getKeyDown(KeyCode::PAGE_UP)) speedUp();
    if (_input.getKeyDown(KeyCode::PAGE_DOWN)) slowDown();
    if (_input.getKeyDown(KeyCode::HOME)) resetSpeed();
}

void SpeedScript::speedUp() {
    double newSpeed = _engineCalls.speed() + SPEED_TICK;
    if (newSpeed <= MAX_SPEED) {
        _engineCalls.modifySpeed(newSpeed);
        _speedUpSound.queueForPlay = true;
        _debug.log("Increased speed to " + std::to_string(_engineCalls.speed()) + "x");
    } else {
        _impossibleToAdjustSound.queueForPlay = true;
        _debug.log("Engine speed is at its maximum and stays " + std::to_string(_engineCalls.speed()) + "x");
    }
}

void SpeedScript::slowDown() {
    double newSpeed = _engineCalls.speed() - SPEED_TICK;
    if (newSpeed >= MIN_SPEED) {
        _engineCalls.modifySpeed(newSpeed);
        _slowDownSound.queueForPlay = true;
        _debug.log("Decreased speed to " + std::to_string(_engineCalls.speed()) + "x");
    } else {
        _impossibleToAdjustSound.queueForPlay = true;
        _debug.log("Engine speed is at its minimum and stays " + std::to_string(_engineCalls.speed()) + "x");
    }
}

void SpeedScript::resetSpeed() {
    _engineCalls.modifySpeed(1.0);
    _resetSound.queueForPlay = true;
    _debug.log("Engine speed reset to " + std::to_string(_engineCalls.speed()) + "x");
}
