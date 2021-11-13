#pragma once

#include <memory>
#include <map>
#include <string>

extern "C" {
    #include "SDL.h"
    #include "SDL_image.h"
}
#include "../../API/GameObjects/Transform.hpp"

class RendererHandler {
    public:
        RendererHandler();

        void LoadTexture(const std::string& fileName);
        void BeginRenderTick();
        void DrawTexture(const std::string& texture, const Transform& location);
        void EndRenderTick();
        void End();
    private:
        int _sdlStatus;
        std::unique_ptr<std::map<std::string, SDL_Texture*>> _textures;
        std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window;
        std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer;
};