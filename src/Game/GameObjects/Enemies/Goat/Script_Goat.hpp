#ifndef GOAT_ENGINE_SCRIPT_GOAT_HPP
#define GOAT_ENGINE_SCRIPT_GOAT_HPP


#include "Object_Goat.hpp"

class Script_Goat : public Script {
public:
    Script_Goat(Object_Player& player, Object_Goat& goat, bool active) : Script(active), _goat(goat),
                                                                         _startPosition(goat.transform.position),
                                                                         _previousPos(goat.transform.position),
                                                                         _player(player) {};

    void onTriggerEnter2D(GameObject& object) override;
    void onUpdate(double deltaTime);

private:
    enum GoatDirection {
        LEFT,
        RIGHT
    };

    Object_Goat& _goat;
    Object_Player& _player;
    Point _startPosition;
    Point _previousPos;
    GoatDirection _direction{LEFT};
    int _walkingSwitchFrameCounter{1};
    bool _isAngry{false};
    int _stuckTimer{0};

    int PATH_LENGTH{1200};      //max length the goat will walk before returning to startposition
    float SPEED_IDLE{200};      //normal walk speed
    float SPEED_ANGRY{450};     //angry walk speed

    void updateDirection();
    void updatePosition();
    void updateSprite();
    bool detectsPlayer();
};


#endif //GOAT_ENGINE_SCRIPT_GOAT_HPP
