#ifndef GOAT_ENGINE_AUDIOSYSTEM_HPP
#define GOAT_ENGINE_AUDIOSYSTEM_HPP

#include "System.hpp"
#include "Apis/AudioApi.hpp"

namespace Engine {
    class AudioSystem : public System {
    public:
        explicit AudioSystem(const Scene *scene);
        void OnInit();
        void OnUpdate(double deltaTime);
        void OnDestroy();

    private:
            AudioApi& _api;
    };
}


#endif //GOAT_ENGINE_AUDIOSYSTEM_HPP
