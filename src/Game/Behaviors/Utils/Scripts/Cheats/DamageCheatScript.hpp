#ifndef GOAT_ENGINE_DAMAGECHEATSCRIPT_HPP
#define GOAT_ENGINE_DAMAGECHEATSCRIPT_HPP

#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"
#include "../../../../GameObjects/Characters/Object_Player.hpp"

using namespace Engine;

class DamageCheatScript : public Script {
    public:
        DamageCheatScript(Object_Player& player, bool active);
        void onUpdate(double deltaTime);

    private:
        Object_Player& _player;
        Input& _input = Input::getInstance();
        Debug& _debug = Debug::getInstance();
};


#endif //GOAT_ENGINE_DAMAGECHEATSCRIPT_HPP
