#ifndef GOAT_ENGINE_PHYSICSAPI_HPP
#define GOAT_ENGINE_PHYSICSAPI_HPP

#include "Implementations/PhysicsImpl.hpp"
#include <memory>
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

        void CreateBody(std::shared_ptr<GameObject> gameObjectPointer);
        void DestroyWorld();
        void DestroyBody(b2Body *body);
        void Update(std::shared_ptr<GameObject> gameObjectPointer);
        void Step();
    private:
        PhysicsApi() : physics() {};
        PhysicsImpl physics;
    };
}


#endif //GOAT_ENGINE_PHYSICSAPI_HPP
