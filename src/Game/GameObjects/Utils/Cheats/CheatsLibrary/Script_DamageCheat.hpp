#ifndef GOAT_ENGINE_SCRIPT_DAMAGECHEAT_HPP
#define GOAT_ENGINE_SCRIPT_DAMAGECHEAT_HPP

#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"
#include "../../../Player/Object_Player.hpp"
#include "../../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class Script_DamageCheat : public Script {
    public:
        Script_DamageCheat(Object_Player& player, bool active);
        void onUpdate(double deltaTime);

    private:
        // Utilities
        Input& _input = Input::getInstance();
        Debug& _debug = Debug::getInstance();
        Globals& _globals = Globals::getInstance();
        // Variables
        Object_Player& _player;
};


#endif //GOAT_ENGINE_SCRIPT_DAMAGECHEAT_HPP
