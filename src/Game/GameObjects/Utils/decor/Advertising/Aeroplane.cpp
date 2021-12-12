#include "Aeroplane.hpp"
#include "../../../../Keys.hpp"
#include "AeroplaneBehavior.hpp"

Aeroplane::Aeroplane(Transform transform,double maxDistance, bool active) : GameObject(transform, active), maxDist(maxDistance) {
sprites.insert(std::make_pair(Keys::AEROPLANE, Sprite{"Sprites/utils/skydecor/airplane.png", true}));
behaviors.insert(std::make_pair(Keys::AEROPLANE, std::make_shared<AeroplaneBehavior>(*this, active)));
}

void Aeroplane::followPlaneMovement(const std::shared_ptr<GameObject>& following) {
    _attachedObjects.emplace_back(following);
}

std::vector<std::shared_ptr<GameObject>> Aeroplane::getAttachedObjects() {
    return _attachedObjects;
}
