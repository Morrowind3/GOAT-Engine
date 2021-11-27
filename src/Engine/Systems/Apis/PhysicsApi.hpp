#ifndef GOAT_ENGINE_PHYSICSAPI_HPP
#define GOAT_ENGINE_PHYSICSAPI_HPP

#include "Implementations/PhysicsImpl.hpp"

using namespace Engine;

namespace Engine {
    class PhysicsApi {
        public:
            PhysicsApi(PhysicsApi const&) = delete;
            void operator=(PhysicsApi const&) = delete;

            static PhysicsApi& getInstance(){
                static PhysicsApi instance{};
                return instance;
            }

            void CreateBody(const GameObject& gameObject);
            void PerformPhysicsCalculationsForFrame();
            void UpdateGameObjectStateFromPhysicsTick(GameObject& gameObject);
            void ResetForNextScene();
        private:
            PhysicsApi() : physics() {};
            PhysicsImpl physics;
    };
}


#endif //GOAT_ENGINE_PHYSICSAPI_HPP
