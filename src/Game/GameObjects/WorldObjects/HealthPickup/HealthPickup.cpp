#include "HealthPickup.hpp"
#include "../../../Keys.hpp"
#include "HealthPickupBehavior.hpp"

HealthPickup::HealthPickup(Transform transform, bool active) : GameObject(transform, active) {
    audioSources.insert(std::make_pair(Keys::JAGERPLEISTER, AudioSource{"Sounds/Heal.ogg", AudioSourceType::SAMPLE, true}));
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<HealthPickupBehavior>(*this, audioSources.at(Keys::JAGERPLEISTER), true)));
    sprites.insert(std::make_pair(Keys::JAGERPLEISTER, Sprite{"Sprites/utils/items/Jägerpleister.png",true}));
    rigidBody = RigidBody(0, 0, BodyType::STATIC, true);
    collider = BoxCollider(20 * transform.scaleWidth, 3 * transform.scaleHeight, true, true);
}
