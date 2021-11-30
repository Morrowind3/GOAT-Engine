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
        EngineCalls& _engineCalls = EngineCalls::getInstance();

        // Variables
        Player& _player;
        // Needed for walking
        int _walkingSwitchFrameCounter{0};
        int _walkingState{0};
        unsigned short _sprintModifier {0};
        bool _walkingStepAltSfx = false;
        // Needed for jumping
        bool _jumpState = false;
        bool _doubleJumpState = false;
        double _yPositionLastFrame = false;

        // Consts
        static const int PLAYER_SPEED = 15000;
        static const unsigned short SPRINT_STEP = 15;
        static const unsigned short MAX_SPRINT_MODIFIER = 400;
        static const int JUMP_FORCE = 1400000;
        constexpr static const double DOUBLE_JUMP_TRIGGER = 0.2;
        constexpr static const double DOUBLE_JUMP_MODIFIER = 1.15;

        // Methods
        float calculateWalkSpeed(double deltaTime);
        // Movement
        void moveLeft(double deltaTime);
        void moveRight(double deltaTime);
        [[nodiscard]] bool allowedToJump() const;
        void jump(double deltaTime);
        [[nodiscard]] bool allowedToDoubleJump(double deltaTime) const;
        void doubleJump(double deltaTime);
        // Visual output
        void updateSpriteStateWhileWalking(bool moveLeft, bool moveRight);
        // Auditory output
        void playWalkSound();
        void playJumpSound();
        // TODO: Pickup trash
};


#endif //GOAT_ENGINE_PLAYERMOVEMENTSCRIPT_HPP
