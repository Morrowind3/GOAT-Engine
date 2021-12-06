#ifndef GOAT_ENGINE_SUMMONSCRIPT_HPP
#define GOAT_ENGINE_SUMMONSCRIPT_HPP

#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"
#include "../../../../../Engine/API/Scene.hpp"
#include "../../../Player/Object_Player.hpp"

using namespace Engine;

class SummonScript : public Script {
    public:
        SummonScript(Scene& scene, Object_Player& player, bool active);
        void onUpdate(double deltaTime);

    private:
        Scene& _scene;
        Object_Player& _player;
        Input& _input = Input::getInstance();
        Debug& _debug = Debug::getInstance();
};


#endif //GOAT_ENGINE_SUMMONSCRIPT_HPP
