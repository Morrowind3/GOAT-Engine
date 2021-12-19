#ifndef GOAT_ENGINE_PHYSICSSYSTEM_HPP
#define GOAT_ENGINE_PHYSICSSYSTEM_HPP

#include "System.hpp"
#include "Apis/PhysicsApi.hpp"

namespace Engine {
    class PhysicsSystem : public System {
        public:
            PhysicsSystem() = default;
            void onLaunchEngine() override;
            void onLoadScene(std::shared_ptr<Scene> scene) override;
            void onFrameTick(double deltaTime) override;
            void onCloseEngine() override;
        private:
            PhysicsApi* _api = nullptr;
    };
}


#endif //GOAT_ENGINE_PHYSICSSYSTEM_HPP
