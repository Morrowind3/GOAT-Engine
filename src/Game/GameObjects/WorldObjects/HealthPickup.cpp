//
// Created by Morrowind3 on 29/11/2021.
//

#include "HealthPickup.hpp"
#include "../../Keys.hpp"
#include "../../Behaviors/WorldObjects/HealthPickupBehavior.hpp"

HealthPickup::HealthPickup(Transform transform, bool active) : GameObject(transform, active) {
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<HealthPickupBehavior>(*this, true)));
    sprites.insert(std::make_pair(Keys::JAGERPLEISTER, Sprite{"Sprites/utils/items/Jägerpleister.png",true}));
    collider = BoxCollider(20 * transform.scaleWidth, 3 * transform.scaleHeight, true);
    rigidBody = RigidBody(0, 0, BodyType::STATIC, true);
}
