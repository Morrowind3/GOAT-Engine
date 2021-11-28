#ifndef GOAT_ENGINE_SCRIPTSYSTEM_HPP
#define GOAT_ENGINE_SCRIPTSYSTEM_HPP

#include "System.hpp"
#include "Apis/PhysicsApi.hpp"

namespace Engine {
    class ScriptSystem : public System  {
        public:
            ScriptSystem() = default;
            void onLaunchEngine() override;
            void onLoadScene(std::shared_ptr<Scene> scene) override;
            void onFrameTick(double deltaTime) override;
            void onCloseEngine() override;
        private:
            PhysicsApi& _physics = PhysicsApi::getInstance();
    };
}



#endif //GOAT_ENGINE_SCRIPTSYSTEM_HPP
