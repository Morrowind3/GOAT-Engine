#ifndef GOAT_ENGINE_RENDERINGSYSTEM_HPP
#define GOAT_ENGINE_RENDERINGSYSTEM_HPP

#include "System.hpp"
#include "../Systems/Apis/RendererApi.hpp"
#include "SystemHelpers/AnimatorHelper.hpp"

namespace Engine {
    class RenderingSystem : public System {
        public:
            RenderingSystem(std::string& name, std::string& iconPath, std::string& cursor);
            void onLaunchEngine() override;
            void onLoadScene(std::shared_ptr<Scene> scene) override;
            void onFrameTick(double deltaTime) override;
            void onCloseEngine() override;
        private:
            // Load scene helper methods
            void loadSpritesData(GameObject& gameObject);
            void loadTextData(GameObject& gameObject);
            void loadButtonsData(GameObject& gameObject);
            // Frame tick helper methods
            void handleAnimators(GameObject& gameObject, double deltaTime);
            void drawSprites(GameObject& gameObject);
            void drawText(GameObject& gameObject);
            void drawButtons(GameObject& gameObject);
            // Variables
            RendererApi* _api = nullptr;
            std::string& _name, _iconPath, _cursor;
            AnimatorHelper _animatorHelper {};
    };
}

#endif //GOAT_ENGINE_RENDERINGSYSTEM_HPP
