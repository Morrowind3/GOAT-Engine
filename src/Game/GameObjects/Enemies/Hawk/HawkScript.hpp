#ifndef GOAT_ENGINE_HAWKSCRIPT_HPP
#define GOAT_ENGINE_HAWKSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Hawk.hpp"
#include "../../../../Engine/Utilities/Debug.hpp"
#include <ctime>

using namespace Engine;

enum HawkDirection {
    LEFT,
    RIGHT,
    DOWN,
    UP
};

class HawkScript : public Script {
public:
    HawkScript(Hawk& self, bool active) : Script(active), _self(self), _startingPos(self.transform.position) {};
    void onUpdate(double deltaTime);
    void onTriggerEnter2D(GameObject &other);

private:
    Hawk& _self;
    Point _startingPos;
    HawkDirection _direction = RIGHT;
    int _updateCounter{0};

    int FLYING_SCOPE{400};  //amount of pixels
    int DIVE_CHANGE{1}; //number between 0-100
    float SPEED_IDLE{0.4};
    float SPEED_DIVING{0.2};   //2.6
    float SPEED_RISING{1.4};

    Debug& _debug = Debug::getInstance();

    void updateDirection();
    void updatePosition();
    void updateSprite();
    static int getRandomBetween(int from, int to);

};


#endif //GOAT_ENGINE_HAWKSCRIPT_HPP
