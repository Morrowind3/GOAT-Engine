#ifndef GOAT_ENGINE_FLAGSCRIPT_HPP
#define GOAT_ENGINE_FLAGSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "VictoryFlag.hpp"
#include "../../Player/Player.hpp"

using namespace Engine;

class FlagScript : public Script {
    public:
        FlagScript(bool active, VictoryFlag& flag);
        void onUpdate(double deltaTime) override;
        void onTriggerEnter2D(GameObject &other) override;
private:
        void animateFlag();
        VictoryFlag& _flag;
        double animationTimer = 0;
};


#endif //GOAT_ENGINE_FLAGSCRIPT_HPP
