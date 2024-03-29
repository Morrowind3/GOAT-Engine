#ifndef GOAT_ENGINE_RENDERERAPI_HPP
#define GOAT_ENGINE_RENDERERAPI_HPP

#include <string>
#include "../../API/GameObjects/Transform.hpp"
#include "Implementations/RendererImpl.hpp"

namespace Engine {
    class RendererApi {
        public:
            RendererApi(RendererApi const&) = delete;
            void operator=(RendererApi const&) = delete;
            static RendererApi& getInstance(std::string& name, std::string& iconPath, std::string& cursor) {
                static RendererApi instance{name, iconPath, cursor};
                return instance;
            }
            void setViewPort(Point dimensions);
            void loadTexture(const std::string& fileName);
            void loadFont(const std::string& fileName);
            void beginRenderTick();
            void drawTexture(const std::string& texture, const std::shared_ptr<Transform>& location);
            void drawText(const Text& text, const std::shared_ptr<Transform>& location);
            void endRenderTick();
            void resetForNextScene();
            void end();

        private:
            RendererApi(std::string& name, std::string& iconPath, std::string& cursor) : renderer(name, iconPath, cursor) {};
            RendererImpl renderer;
    };
}

#endif //GOAT_ENGINE_RENDERERAPI_HPP
