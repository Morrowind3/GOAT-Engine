#ifndef GOAT_ENGINE_GOATSCRIPT_HPP
#define GOAT_ENGINE_GOATSCRIPT_HPP


#include "Goat.hpp"

class GoatScript : public Script {
public:
    GoatScript(Goat& goat, bool active): Script(active), _goat(goat), _startPosition(goat.transform.position){};
    void onTriggerEnter2D(GameObject& object) override;
    void onUpdate(double deltaTime);

private:
    Goat& _goat;
    Point _startPosition;
    //0 = left, 1 = right
    int _direction{0};
    int _pathLength{1600};
    float _idleSpeed{150};
    float _angrySpeed{400};
    int _walkingSwitchFrameCounter{1};

    void switchDirection();
    void walk();
};


#endif //GOAT_ENGINE_GOATSCRIPT_HPP
