#ifndef GOAT_ENGINE_PLAYERMOVEMENTSCRIPT_HPP
#define GOAT_ENGINE_PLAYERMOVEMENTSCRIPT_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/Utilities/Input.hpp"
#include "../../../Engine/Utilities/Globals.hpp"
#include "Object_Player.hpp"

using namespace Engine;

class PlayerMovementScript : public Script {
    public:
        PlayerMovementScript(Object_Player& player, bool active);
        void onUpdate(double deltaTime) override;
        void onTriggerEnter2D(GameObject& other);
        void onTriggerStay2D(GameObject& other);

    private:
        // Globals
        Input& _input = Input::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();

        // Variables
        Object_Player& _player;
        // Needed for walking
        bool _walkState {false};
        double _walkingSoundCounter {WALK_SOUND_PER_MS_AMOUNT};
        unsigned short _sprintModifier {0};
        bool _walkingStepAltSfx {false};
        // Needed for jumping
        bool _jumpState {false};
        bool _doubleJumpState {false};
        double _yPositionLastFrame {false};
        // Needed to pickup trash
        double _pickUpTrashTimer {0.0};

        // Consts
        static const int PLAYER_SPEED = 15000;
        static const unsigned short SPRINT_STEP = 15;
        static const unsigned short MAX_SPRINT_MODIFIER = 400;
        static const int JUMP_FORCE = 1000000;
        constexpr static const double DOUBLE_JUMP_MODIFIER = 1.15;
        constexpr static const double WALK_SOUND_PER_MS_AMOUNT = 1000.0/3.0;
        constexpr static const double PICKUP_TRASH_GRACE_IN_MS = 1000.0/4.0;

        // Methods
        // Movement logic
        float calculateWalkSpeed(double deltaTime);
        void moveLeft(double deltaTime);
        void moveRight(double deltaTime);
        [[nodiscard]] bool allowedToJump() const;
        void jump(double deltaTime);
        [[nodiscard]] bool allowedToDoubleJump(double deltaTime) const;
        void doubleJump(double deltaTime);
        [[nodiscard]] bool allowedToPickupTrash() const;
        void pickupTrash(GameObject& other);
        void resetAtNonWalkingState();
        // Visual output
        void updateSpriteState();
        void hideWalkingSprites();
        void makeSurePlayerIsVisible();
        // Auditory output
        void playWalkSound(double deltaTime);
        void playJumpSound();
};


#endif //GOAT_ENGINE_PLAYERMOVEMENTSCRIPT_HPP
