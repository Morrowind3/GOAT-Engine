#ifndef GOAT_ENGINE_SCRIPT_VICTORYFLAG_HPP
#define GOAT_ENGINE_SCRIPT_VICTORYFLAG_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Object_VictoryFlag.hpp"

using namespace Engine;

class Script_VictoryFlag : public Script {
    public:
        Script_VictoryFlag(bool active, Object_VictoryFlag& flag);
        void onUpdate(double deltaTime) override;
        void onTriggerEnter2D(GameObject &other) override;
private:
        void animateFlag();
        Object_VictoryFlag& _flag;
        double animationTimer = 0;
};


#endif //GOAT_ENGINE_SCRIPT_VICTORYFLAG_HPP
