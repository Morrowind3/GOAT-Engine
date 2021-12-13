#include "Object_HealthPickup.hpp"
#include "../../../Keys.hpp"
#include "Behavior_HealthPickup.hpp"

Object_HealthPickup::Object_HealthPickup(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair(Keys::JAGERPLEISTER, AudioSource{"Sounds/Heal.ogg", AudioSourceType::SAMPLE, true}));
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<Behavior_HealthPickup>(*this, audioSources.at(Keys::JAGERPLEISTER), true)));
    sprites.insert(std::make_pair(Keys::JAGERPLEISTER, Sprite{"Sprites/utils/items/Jägerpleister.png",true}));
    rigidBody = RigidBody(0, 0, BodyType::STATIC, true);
    collider = BoxCollider(20 * transform.scaleWidth, 3 * transform.scaleHeight, 0,true, true);
}
