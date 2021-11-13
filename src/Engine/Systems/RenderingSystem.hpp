#pragma once

#include "System.hpp"

namespace Engine {
    class RenderingSystem : public System {
        public:
            explicit RenderingSystem(const Scene* scene);
            void OnInit();
            void OnUpdate();
            void OnDestroy();
    };
}
