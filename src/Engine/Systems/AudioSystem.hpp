#ifndef GOAT_ENGINE_AUDIOSYSTEM_HPP
#define GOAT_ENGINE_AUDIOSYSTEM_HPP

#include "System.hpp"

namespace Engine {
    class AudioSystem : public System {
    public:
        explicit AudioSystem(const Scene *scene);
        void OnInit();
        void OnUpdate(double deltaTime);
        void OnDestroy();
    };
}


#endif //GOAT_ENGINE_AUDIOSYSTEM_HPP
