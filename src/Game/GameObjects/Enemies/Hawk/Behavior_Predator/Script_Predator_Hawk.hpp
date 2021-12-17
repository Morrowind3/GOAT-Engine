#ifndef GOAT_ENGINE_SCRIPT_PREDATOR_HAWK_HPP
#define GOAT_ENGINE_SCRIPT_PREDATOR_HAWK_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../Object_Hawk.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class Script_Predator_Hawk : public Script {
public:
    Script_Predator_Hawk(Object_Player& player, Object_Hawk& self, bool active) : Script(active), _self(self),
        _startingPos(self.transform.position), _player(player) {};
    void onUpdate(double deltaTime);
    void onTriggerEnter2D(GameObject &other);

private:
    enum HawkDirection {
        LEFT,
        RIGHT,
        DOWN,
        UP
    };

    Object_Hawk& _self;
    Object_Player& _player;
    Point _startingPos;
    HawkDirection _direction = RIGHT;
    int _updateCounter{0};
    int _circledAfterDiveCounter{0};
    Debug& _debug = Debug::getInstance();

    int FLYING_SCOPE{400};          //amount of pixels
    int CIRCLES_BETWEEN_DIVES{2};   //amount of circles the hawk has to fly between each dive
    int MAX_DIVE_DEPTH{600};        //amount of pixels before going back up
    int SENSOR_WIDTH{400};          //amount of pixels around hawk player can be detected
    float SPEED_IDLE{1.4};          //circling speed
    float SPEED_DIVING{8.0};        //diving speed
    float SPEED_RISING{2.0};        //rising speed

    void updateDirection();
    void updatePosition();
    void updateSprite();
    bool detectsPlayer();

};


#endif //GOAT_ENGINE_SCRIPT_PREDATOR_HAWK_HPP
