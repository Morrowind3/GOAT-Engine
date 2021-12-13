#ifndef GOAT_ENGINE_SCRIPT_TIMER_HPP
#define GOAT_ENGINE_SCRIPT_TIMER_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"
#include "../../../../Engine/Utilities/Clock.hpp"

using namespace Engine;


class Script_Timer : public Script {
public:
    Script_Timer(Text& timerText, bool active): Script(active), _text(timerText){};
    void onUpdate(double deltaTime) override;
    void onExternalEvent() override; //write time to database and scene data.
private:
    void addSecond();
    Text& _text;
    double _totalMs = 0;
    int _totalSeconds = 0;
    Clock& _clock = Clock::getInstance();
    EngineCalls& _engineCalls = EngineCalls::getInstance();
};


#endif //GOAT_ENGINE_SCRIPT_TIMER_HPP
