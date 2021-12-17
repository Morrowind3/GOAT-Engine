#ifndef GOAT_ENGINE_SCRIPT_DAMAGE_HPP
#define GOAT_ENGINE_SCRIPT_DAMAGE_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/Utilities/Globals.hpp"

using namespace Engine;


class Script_Damage : public Script{
    public:
        explicit Script_Damage(GameObject& actor, bool active): Script(active), _actor(actor){};
        void onExternalEvent() override;
        void onUpdate(double deltaTime) override;
        void onDestroy() override;
    private:
        // Utilities
        Globals& _globals = Globals::getInstance();
        // Constants
        static const int GRACE_PERIOD = 1500;
        // Variables
        double _graceTimer = GRACE_PERIOD;
        GameObject& _actor;
};


#endif //GOAT_ENGINE_SCRIPT_DAMAGE_HPP
