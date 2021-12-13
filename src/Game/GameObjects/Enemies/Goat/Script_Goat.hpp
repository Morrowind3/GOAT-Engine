#ifndef GOAT_ENGINE_SCRIPT_GOAT_HPP
#define GOAT_ENGINE_SCRIPT_GOAT_HPP


#include "Object_Goat.hpp"

enum GoatDirection {
    LEFT,
    RIGHT
};

class Script_Goat : public Script {
public:
    Script_Goat(Object_Goat& goat, bool active): Script(active), _goat(goat), _startPosition(goat.transform.position){};
    void onTriggerEnter2D(GameObject& object) override;
    void onUpdate(double deltaTime);

private:
    Object_Goat& _goat;
    Point _startPosition;
    GoatDirection _direction{LEFT};
    int _walkingSwitchFrameCounter{1};

    int PATH_LENGTH{1200};      //max length the goat will walk before returning to startposition
    float SPEED_IDLE{200};      //normal walk speed
    float SPEED_ANGRY{450};     //angry walk speed

    void updateDirection();
    void updatePosition();
    void updateSprite();
};


#endif //GOAT_ENGINE_SCRIPT_GOAT_HPP
