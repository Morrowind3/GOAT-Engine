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

        static RendererApi& getInstance(std::string& name, std::string& iconPath) {
            static RendererApi instance{name, iconPath};
            return instance;
        }
        void LoadTexture(const std::string& fileName);
        void LoadFont(const std::string& fileName);
        void BeginRenderTick();
        void DrawTexture(const std::string& texture, const Transform& location);
        void DrawText(const std::string& text, uint8_t size, Color color, const std::string& fontName, const Transform& transform);
        void DrawSolid(Color color, const Rectangle& dimensions);
        void EndRenderTick();
        void End();

    private:
        RendererApi(std::string& name, std::string& iconPath) : renderer(name, iconPath) {};
        RendererImpl renderer;
    };
}

#endif //GOAT_ENGINE_RENDERERAPI_HPP
