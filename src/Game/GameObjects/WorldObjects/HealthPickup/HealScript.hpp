#ifndef GOAT_ENGINE_HEALSCRIPT_HPP
#define GOAT_ENGINE_HEALSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "HealthPickup.hpp"

using namespace Engine;

class HealScript : public Script {
    public:
        HealScript(HealthPickup& pickup, AudioSource& healSfx, bool active);
        void onTriggerEnter2D(GameObject &other) override;
        void onUpdate(double deltaTime) override;
    private:
        double _originalY;
        double _animationtimer = 0;
        bool _movingUp = true;
        unsigned short _queueForDeactivation {0};
        HealthPickup& _pickup;
        AudioSource& _healSfx;
};

#endif //GOAT_ENGINE_HEALSCRIPT_HPP
