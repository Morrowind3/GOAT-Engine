#ifndef GOAT_ENGINE_SCRIPT_GOAT_HPP
#define GOAT_ENGINE_SCRIPT_GOAT_HPP

#include "Object_Goat.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

class Script_Goat : public Script {
    public:
        Script_Goat(Object_Player& player, Object_Goat& goat, bool active) : Script(active), _goat(goat),
                                                                             _startPosition(goat.transform.position),
                                                                             _previousPos(goat.transform.position),
                                                                             _player(player) {};
        void onTriggerEnter2D(GameObject& object) override;
        void onUpdate(double deltaTime) override;

    private:

        enum class GoatDirection {
            LEFT,
            RIGHT
        };
        // Utilities
        Globals& _globals = Globals::getInstance();
        // Variables
        Object_Goat& _goat;
        Object_Player& _player;
        Point _startPosition;
        Point _previousPos;
        GoatDirection _direction{GoatDirection::LEFT};
        int _walkingSwitchFrameCounter{1};
        bool _isAngry{false};
        bool _wasAngryLastFrame{false};
        int _stuckTimer{0};
        // Constants
        const int PATH_LENGTH {1200};      // Max length the goat will walk before returning to start position
        const float SPEED_IDLE{200};       // Normal walk speed
        const float SPEED_ANGRY{450};      // Angry walk speed
        const float SENSOR_WIDTH {600};
        const float FLIP_FORCE {700};
        // Helper methods
        void updateDirection();
        void updatePosition();
        void updateSprite();
        bool detectsPlayer();
};


#endif //GOAT_ENGINE_SCRIPT_GOAT_HPP
