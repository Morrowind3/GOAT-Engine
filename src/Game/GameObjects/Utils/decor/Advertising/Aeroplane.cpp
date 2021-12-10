//
// Created by Morrowind3 on 10/12/2021.
//

#include "Aeroplane.hpp"
#include "../../../../Keys.hpp"

Aeroplane::Aeroplane(Transform transform, bool active) : GameObject(transform, active) {
sprites.insert(std::make_pair(Keys::AEROPLANE, Sprite{"Sprites/utils/skydecor/airplane.png", true}));
}

void Aeroplane::followPlaneMovement(const std::shared_ptr<Transform>& otherObject) {
    _attachedObjects.emplace_back(otherObject);
}
