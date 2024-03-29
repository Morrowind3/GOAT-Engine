#ifndef GOAT_ENGINE_OBJECT_AEROPLANE_HPP
#define GOAT_ENGINE_OBJECT_AEROPLANE_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_Aeroplane : public GameObject {
    public:
        Object_Aeroplane(Transform transform, double maxDistance, bool active);
        void followPlaneMovement(const std::shared_ptr<GameObject>& following);
        std::vector<std::shared_ptr<GameObject>> getAttachedObjects();
        const double maxDist;
    private:
        std::vector<std::shared_ptr<GameObject>> _attachedObjects;
};


#endif //GOAT_ENGINE_OBJECT_AEROPLANE_HPP
