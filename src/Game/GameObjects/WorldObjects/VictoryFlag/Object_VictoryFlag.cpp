#include "Object_VictoryFlag.hpp"
#include "../../../Keys.hpp"
#include "Behavior_VictoryFlag.hpp"


Object_VictoryFlag::Object_VictoryFlag( Transform transform, bool active) : GameObject(transform, active) {
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<Behavior_VictoryFlag>(*this, true)));
    sprites.insert(std::make_pair("Default", Sprite{"Sprites/utils/flag/Flag.png",true}));
    sprites.insert(std::make_pair("Wave", Sprite{"Sprites/utils/flag/Flag_wave.png",false}));
    collider = BoxCollider(21 * transform.scaleWidth, 7 * transform.scaleHeight, 0,0,true, true);
    rigidBody = RigidBody(1.0f, 1.0f, BodyType::STATIC, true);
}