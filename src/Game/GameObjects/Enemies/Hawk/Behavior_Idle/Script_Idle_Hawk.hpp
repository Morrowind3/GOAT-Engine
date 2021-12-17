#ifndef GOAT_ENGINE_SCRIPT_IDLE_HAWK_HPP
#define GOAT_ENGINE_SCRIPT_IDLE_HAWK_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../Object_Hawk.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;



class Script_Idle_Hawk : public Script {
public:
    Script_Idle_Hawk(Object_Hawk& self, bool active) : Script(active), _self(self), _startingPos(self.transform.position) {};
    void onUpdate(double deltaTime);

private:
    enum HawkDirection {
        LEFT,
        RIGHT,
    };

    Object_Hawk& _self;
    Point _startingPos;
    HawkDirection _direction = RIGHT;
    int _updateCounter{0};

    int FLYING_SCOPE{400};          //amount of pixels
    float SPEED_IDLE{1.4};          //circling speed

    void updateDirection();
    void updatePosition();
    void updateSprite();

};


#endif //GOAT_ENGINE_SCRIPT_IDLE_HAWK_HPP
