#ifndef GOAT_ENGINE_SCRIPT_SNOWBALL_HPP
#define GOAT_ENGINE_SCRIPT_SNOWBALL_HPP


#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "Object_Snowball.hpp"

using namespace Engine;

class Script_Snowball : public Script {
public:
    Script_Snowball(Object_Snowball& snowball, bool active) :
            Script(active),
            _snowball(snowball),
            _startPosition(snowball.transform.position),
            _prevPos(snowball.transform.position) {
        _startPosition.y -= 200;
        _prevPos.y -= 200;
    };

    void onTriggerEnter2D(GameObject& other) override;
    void onUpdate(double deltaTime) override;

private:
    void respawn();

    Object_Snowball& _snowball;
    std::shared_ptr<Behavior> _paralyzedObject;
    int _paralyzedDuration{0};
    int _spriteRotateDelayKeeper{1};
    Point _startPosition;
    Point _prevPos;
    int _reactivateBodyCounter{2};
    int _stuckCounter{0};

    float PUSH_FORCE{50000};
    int PARALYZE_DURATION{100};
};

#endif //GOAT_ENGINE_SCRIPT_SNOWBALL_HPP
