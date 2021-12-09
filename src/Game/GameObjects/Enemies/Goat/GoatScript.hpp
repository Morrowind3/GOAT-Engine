#ifndef GOAT_ENGINE_GOATSCRIPT_HPP
#define GOAT_ENGINE_GOATSCRIPT_HPP


#include "Goat.hpp"

enum GoatDirection {
    LEFT,
    RIGHT
};

class GoatScript : public Script {
public:
    GoatScript(Goat& goat, bool active): Script(active), _goat(goat), _startPosition(goat.transform.position){};
    void onTriggerEnter2D(GameObject& object) override;
    void onUpdate(double deltaTime);

private:
    Goat& _goat;
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


#endif //GOAT_ENGINE_GOATSCRIPT_HPP
