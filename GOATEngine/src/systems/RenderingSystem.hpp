#ifndef GOATENGINE_RENDERINGSYSTEM_HPP
#define GOATENGINE_RENDERINGSYSTEM_HPP

#include "../core/System.hpp"
#include "apis/RendererApi.hpp"
#include "../managers/TextureManager.hpp"

namespace Engine {
    class RenderingSystem : public System {
        public:
            RenderingSystem(SceneManager& manager);
            void onInit();
            void onUpdate();
            void onDestroy();
        private:
            std::unique_ptr<TextureManager> _textureManager;
    };
}

#endif //GOATENGINE_RENDERINGSYSTEM_HPP
