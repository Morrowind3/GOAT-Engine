//
// Created by Morrowind3 on 10/12/2021.
//

#ifndef GOAT_ENGINE_AEROPLANE_HPP
#define GOAT_ENGINE_AEROPLANE_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Aeroplane : public GameObject {
    public:
        Aeroplane(Transform transform, bool active);
        void followPlaneMovement(const std::shared_ptr<Transform>& transform);
    private:
        std::vector<std::shared_ptr<Transform>> _attachedObjects;
};


#endif //GOAT_ENGINE_AEROPLANE_HPP
