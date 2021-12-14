#ifndef GOAT_ENGINE_SCRIPT_DAMAGECHEAT_HPP
#define GOAT_ENGINE_SCRIPT_DAMAGECHEAT_HPP

#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"
#include "../../../Player/Object_Player.hpp"

using namespace Engine;

class Script_DamageCheat : public Script {
    public:
        Script_DamageCheat(Object_Player& player, bool active);
        void onUpdate(double deltaTime);

    private:
        Object_Player& _player;
        Input& _input = Input::getInstance();
        Debug& _debug = Debug::getInstance();
};


#endif //GOAT_ENGINE_SCRIPT_DAMAGECHEAT_HPP
