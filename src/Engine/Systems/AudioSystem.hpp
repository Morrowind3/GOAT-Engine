#ifndef GOAT_ENGINE_AUDIOSYSTEM_HPP
#define GOAT_ENGINE_AUDIOSYSTEM_HPP

#include "System.hpp"
#include "Apis/AudioApi.hpp"

namespace Engine {
    class AudioSystem : public System {
        public:
            AudioSystem() = default;
            void onLaunchEngine() override;
            void onLoadScene(std::shared_ptr<Scene> scene) override;
            void onFrameTick(double deltaTime) override;
            void onCloseEngine() override;
        private:
            AudioApi* _api = nullptr;
    };
}


#endif //GOAT_ENGINE_AUDIOSYSTEM_HPP
