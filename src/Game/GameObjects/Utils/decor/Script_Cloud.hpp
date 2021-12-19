#ifndef GOAT_ENGINE_SCRIPT_CLOUD_HPP
#define GOAT_ENGINE_SCRIPT_CLOUD_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Object_Cloud.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class Script_Cloud : public Script {
    public:
        Script_Cloud(Object_Cloud& cloud, bool active);
        void onUpdate(double deltaTime) override;
    private:
        // Utilities
        Globals& _globals = Globals::getInstance();
        // Variables
        double _wind {0.5};
        double _timeSinceLastTurn {0};
        Object_Cloud& _cloud;
        // Constants
        const double DURATION_BEFORE_OTHER_DIRECTION_IN_MS {6000};
};


#endif //GOAT_ENGINE_SCRIPT_CLOUD_HPP
