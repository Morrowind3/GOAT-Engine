//
// Created by MDstu on 22/11/2021.
//

#ifndef GOAT_ENGINE_COLLISIONSYSTEM_HPP
#define GOAT_ENGINE_COLLISIONSYSTEM_HPP

#include "System.hpp"
#include "Apis/PhysicsApi.hpp"

namespace Engine {
    class CollisionSystem : public System {
    public:
        explicit CollisionSystem(const Scene* scene);
        void OnInit();
        void OnUpdate(double deltaTime);
        void OnDestroy();
    private:
        PhysicsApi& _api;
    };
}


#endif //GOAT_ENGINE_COLLISIONSYSTEM_HPP
