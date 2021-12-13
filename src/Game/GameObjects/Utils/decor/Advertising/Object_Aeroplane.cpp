#include "Object_Aeroplane.hpp"
#include "../../../../Keys.hpp"
#include "Behavior_Aeroplane.hpp"

Object_Aeroplane::Object_Aeroplane(Transform transform,double maxDistance, bool active) : GameObject(transform, active), maxDist(maxDistance) {
sprites.insert(std::make_pair(Keys::AEROPLANE, Sprite{"Sprites/utils/skydecor/airplane.png", true}));
behaviors.insert(std::make_pair(Keys::AEROPLANE, std::make_shared<Behavior_Aeroplane>(*this, active)));
}

void Object_Aeroplane::followPlaneMovement(const std::shared_ptr<GameObject>& following) {
    _attachedObjects.emplace_back(following);
}

std::vector<std::shared_ptr<GameObject>> Object_Aeroplane::getAttachedObjects() {
    return _attachedObjects;
}
