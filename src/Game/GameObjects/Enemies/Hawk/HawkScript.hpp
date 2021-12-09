#ifndef GOAT_ENGINE_HAWKSCRIPT_HPP
#define GOAT_ENGINE_HAWKSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Hawk.hpp"

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
    int _circledAfterDiveCounter{0};

    int FLYING_SCOPE{400};      //amount of pixels
    int CIRCLES_BEFORE_DIVE{2}; //amount of circles the hawk has to fly between each dive
    int DIVE_CHANGE{1};         //number between 1-1000, the higher, the more dive change
    int MAX_DIVE_DEPTH{600};    //amount of pixels before going back up
    float SPEED_IDLE{1.4};      //circling speed
    float SPEED_DIVING{5.0};    //diving speed
    float SPEED_RISING{2.0};    //rising speed

    void updateDirection();
    void updatePosition();
    void updateSprite();
    static int getRandomBetween(int from, int to);

};


#endif //GOAT_ENGINE_HAWKSCRIPT_HPP
