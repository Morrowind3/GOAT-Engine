#ifndef GOAT_ENGINE_SUMMONSCRIPT_HPP
#define GOAT_ENGINE_SUMMONSCRIPT_HPP

#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"
#include "../../../Player/Player.hpp"
#include "../../../../../Engine/API/Scene.hpp"

using namespace Engine;

class SummonScript : public Script {
    public:
        SummonScript(Scene& scene, Player& player, bool active);
        void onUpdate(double deltaTime);

    private:
        Scene& _scene;
        Player& _player;
        Input& _input = Input::getInstance();
        Debug& _debug = Debug::getInstance();
};


#endif //GOAT_ENGINE_SUMMONSCRIPT_HPP
