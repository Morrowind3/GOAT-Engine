#ifndef GOAT_ENGINE_PLAYERMOVEMENTSCRIPT_HPP
#define GOAT_ENGINE_PLAYERMOVEMENTSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/Input.hpp"
#include "../../../GameObjects/Characters/Player.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class PlayerMovementScript : public Script {
    public:
        PlayerMovementScript(Player& player, bool active);
        void OnUpdate(double deltaTime);
    private:
        // Globals
        Input& _input = Input::GetInstance();
        Globals& _globals = Globals::GetInstance();
        // Variables
        Player& _player;
        int _counter{0};
        int _walkingState{0};
        bool _jumpState = false;
        bool _jumpStepAltSfx = false;
        // Consts
        static const int PLAYER_SPEED = 1000;
};


#endif //GOAT_ENGINE_PLAYERMOVEMENTSCRIPT_HPP
