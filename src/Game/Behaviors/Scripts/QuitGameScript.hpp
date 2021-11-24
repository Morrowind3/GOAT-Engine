#ifndef GOAT_ENGINE_QUITGAMESCRIPT_HPP
#define GOAT_ENGINE_QUITGAMESCRIPT_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class QuitGameScript : public Script {
    public:
        explicit QuitGameScript(bool active);
        void OnExternalEvent();
};


#endif //GOAT_ENGINE_QUITGAMESCRIPT_HPP
