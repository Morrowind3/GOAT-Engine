#include "Script_TimerLine.hpp"
#include "../../../Keys.hpp"

Script_TimerLine::Script_TimerLine(Object_TimerLine& timerLine, double speed, bool active) : Script(active), _speed(speed), _timerLine(timerLine){}

/// Difficulty adjusts line
void Script_TimerLine::onStart() {
    int difficulty = std::stoi(_globals.gameGet(Keys::DIFFICULTY));
    _speed *= (difficulty/100.0);
    storePosition();
}

/// Update position of line
void Script_TimerLine::onUpdate(double deltaTime) {
    if(_engineCalls.isPaused()) return;
    _timerLine.transform.position.x = _timerLine.transform.position.x + _speed * _engineCalls.speed();
    storePosition();
}

void Script_TimerLine::storePosition() {
    _globals.gameStore(Keys::LINE_LOCATION, std::to_string((int)_timerLine.transform.position.x));
}


