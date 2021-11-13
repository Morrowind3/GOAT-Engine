#ifndef GOATENGINE_RENDERINGSYSTEM_HPP
#define GOATENGINE_RENDERINGSYSTEM_HPP

#include "../core/System.hpp"
#include "apis/RendererApi.hpp"
#include "../managers/TextureManager.hpp"
#include "../managers/SceneManager.hpp"

namespace Engine {
    class RenderingSystem : public System {
        public:
            explicit RenderingSystem(SceneManager& manager);
            void onInit();
            void onDestroy();
            void onSceneLoad(Scene &scene) override;
            void onSceneUnload(Scene &scene) override;
            void onUpdate(double deltaTime) override;
        private:
            std::unique_ptr<TextureManager> _textureManager;
    };
}

#endif //GOATENGINE_RENDERINGSYSTEM_HPP
