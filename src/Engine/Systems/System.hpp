#pragma once

#include "../API/Scene.hpp"

namespace Engine {
    class System {
        public:
            explicit System(const Scene* scene);
            virtual void OnInit() = 0;
            virtual void OnUpdate() = 0;
            virtual void OnDestroy() = 0;
        protected:
            const Scene* _scene;
    };
}
