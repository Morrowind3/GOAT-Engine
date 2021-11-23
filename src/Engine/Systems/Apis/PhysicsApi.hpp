//
// Created by MDstu on 21/11/2021.
//

#ifndef GOAT_ENGINE_PHYSICSAPI_HPP
#define GOAT_ENGINE_PHYSICSAPI_HPP

#include "Implementations/PhysicsImpl.hpp"
#include <memory>
using namespace Engine;

namespace Engine {
    class PhysicsApi {
    public:
        static PhysicsApi& getInstance(){
            static PhysicsApi instance{};
            return instance;
        }
        void CreateWorld();
        void DestroyWorld();
        void DestroyBody(b2Body *body);
        void Update(GameObject &gameObject);
        void Step();
    private:
        std::unique_ptr<PhysicsImpl> _impl;
    };
}


#endif //GOAT_ENGINE_PHYSICSAPI_HPP
