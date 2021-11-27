#ifndef GOAT_ENGINE_COLLISIONSYSTEM_HPP
#define GOAT_ENGINE_COLLISIONSYSTEM_HPP

#include "System.hpp"
#include "Apis/PhysicsApi.hpp"

namespace Engine {
    class CollisionSystem : public System {
        public:
            CollisionSystem() = default;
            void OnLaunchEngine() override;
            void OnLoadScene(std::shared_ptr<Scene> scene) override;
            void OnFrameTick(double deltaTime) override;
            void OnCloseEngine() override;
        private:
            PhysicsApi* _api = nullptr;
    };
}


#endif //GOAT_ENGINE_COLLISIONSYSTEM_HPP
