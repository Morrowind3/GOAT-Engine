#ifndef GOAT_ENGINE_SCRIPT_HEAL_HPP
#define GOAT_ENGINE_SCRIPT_HEAL_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Object_HealthPickup.hpp"

using namespace Engine;

class Script_Heal : public Script {
    public:
        Script_Heal(Object_HealthPickup& pickup, AudioSource& healSfx, bool active);
        void onTriggerEnter2D(GameObject &other) override;
        void onUpdate(double deltaTime) override;
    private:
        double _originalY;
        double _animationtimer = 0;
        bool _movingUp = true;
        unsigned short _queueForDeactivation {0};
        Object_HealthPickup& _pickup;
        AudioSource& _healSfx;
};

#endif //GOAT_ENGINE_SCRIPT_HEAL_HPP
