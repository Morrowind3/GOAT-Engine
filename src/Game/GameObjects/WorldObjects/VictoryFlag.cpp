#include "VictoryFlag.hpp"
#include "../../Keys.hpp"
#include "../../Behaviors/WorldObjects/VictoryFlagBehavior.hpp"


VictoryFlag::VictoryFlag(Transform transform, bool active) : GameObject(transform, active) {
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<VictoryFlagBehavior>(*this, true)));
    sprites.insert(std::make_pair("Default", Sprite{"Sprites/utils/flag/Flag.png",true}));
    sprites.insert(std::make_pair("Wave", Sprite{"Sprites/utils/flag/Flag_wave.png",false}));
    collider = BoxCollider(21 * transform.scaleWidth, 7 * transform.scaleHeight, true, true);
    rigidBody = RigidBody(1.0f, 1.0f, BodyType::STATIC, true);
}