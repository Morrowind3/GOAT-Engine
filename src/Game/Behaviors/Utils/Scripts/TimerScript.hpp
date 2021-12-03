//
// Created by Morrowind3 on 01/12/2021.
//

#ifndef GOAT_ENGINE_TIMERSCRIPT_HPP
#define GOAT_ENGINE_TIMERSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"
#include "../../../../Engine/Utilities/Clock.hpp"

using namespace Engine;


class TimerScript : public Script {
public:
    TimerScript(Text& timerText, bool active): Script(active), _text(timerText){};
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


#endif //GOAT_ENGINE_TIMERSCRIPT_HPP
