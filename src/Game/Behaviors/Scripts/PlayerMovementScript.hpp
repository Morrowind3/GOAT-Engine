#ifndef GOAT_ENGINE_PLAYERMOVEMENTSCRIPT_HPP
#define GOAT_ENGINE_PLAYERMOVEMENTSCRIPT_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/Utilities/Input.hpp"
#include "../../GameObjects/Characters/Player.hpp"

using namespace Engine;

class PlayerMovementScript : public Script {
    public:
        PlayerMovementScript(Player& player, bool active);
        void OnUpdate(double deltaTime);
    private:
        Player& _player;
        Input& _input;
        bool _jumpState = false;
        bool _jumpStepAltSfx = false;
        // Consts
        static const int PLAYER_SPEED = 4;
};


#endif //GOAT_ENGINE_PLAYERMOVEMENTSCRIPT_HPP
