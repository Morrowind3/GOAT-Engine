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
        void onUpdate(double deltaTime);
        void onTriggerEnter2D(GameObject& other);

    private:
        // Globals
        Input& _input = Input::getInstance();
        Globals& _globals = Globals::getInstance();

        // Variables
        Player& _player;
        // Needed for walking
        int _walkingSwitchFrameCounter{0};
        int _walkingState{0};
        bool _walkingStepAltSfx = false;
        // Needed for jumping
        bool _jumpState = false;
        bool _doubleJumpState = false;
        double _yPositionLastFrame = false;

        // Consts
        static const int PLAYER_SPEED = 1000;
        static const int JUMP_FORCE = 60000;
        constexpr static const double DOUBLE_JUMP_TRIGGER = 0.2;
        constexpr static const double DOUBLE_JUMP_MODIFIER = 1.4;

        // Methods
        // Movement
        void moveLeft();
        void moveRight();
        [[nodiscard]] bool allowedToJump() const;
        void jump();
        [[nodiscard]] bool allowedToDoubleJump(double deltaTime) const;
        void doubleJump();
        // Visual output
        void updateSpriteStateWhileWalking(bool moveLeft, bool moveRight);
        // Auditory output
        void playWalkSound();
        void playJumpSound();
        // TODO: Pickup trash
};


#endif //GOAT_ENGINE_PLAYERMOVEMENTSCRIPT_HPP
