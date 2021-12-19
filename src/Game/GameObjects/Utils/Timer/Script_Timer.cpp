#include "Script_Timer.hpp"
#include "../../../Keys.hpp"

Script_Timer::Script_Timer(Text& timerText, bool active) : Script(active), _text(timerText){}

void Script_Timer::onUpdate(double deltaTime) {
    storeState();
    if (_engineCalls.isPaused()) return; // Do not count when game is paused
    _totalMs += _clock.lastRecordedUnmodifiedDeltaTime();
    if((int) _totalMs * _engineCalls.speed() / 1000 >= 1){
        addSecond();    // Minimize UI updates
        _totalMs = 0;
    }
}

void Script_Timer::addSecond() {
    ++_totalSeconds;

    std::string timeString;
    timeString.reserve(5);
    int minutes = _totalSeconds / 60;
    int seconds = _totalSeconds % 60;

    if(minutes < 10){
        timeString.insert(0, "0" + std::to_string(minutes));
    } else {
        timeString.insert(0, std::to_string(minutes));
    }
    timeString.insert(2, ":");

    if(seconds < 10){
        timeString.insert(3, "0" + std::to_string(seconds));
    } else {
        timeString.insert(3, std::to_string(seconds));
    }

    _text.text = timeString;
}

void Script_Timer::storeState() {
    _globals.gameStore(Keys::TIMER, std::to_string(_totalSeconds*1000+(int)_totalMs));
    _globals.gameStore(Keys::TIMER_TEXT, _text.text);
}
