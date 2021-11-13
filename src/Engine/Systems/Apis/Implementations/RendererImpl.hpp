#ifndef GOAT_ENGINE_RENDERERIMPL_HPP
#define GOAT_ENGINE_RENDERERIMPL_HPP

#include <memory>
#include <map>
#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "../../../API/GameObjects/GameObject.hpp"
#include "../../../Resources/Texture.hpp"
#include "../../../API/GameObjects/Transform.hpp"

namespace Engine {
    class RendererImpl {
        public:
            RendererImpl();

            void LoadTexture(const std::string& fileName);

            void BeginRenderTick();

            void DrawTexture(const std::string& texture, const Transform& location);

            void EndRenderTick();

            void End();

        private:
            int _sdlStatus;
            std::unique_ptr<std::map<std::string, SDL_Texture*>> _textures;
            std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> _window;
            std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)> _renderer;
    };
}

#endif //GOAT_ENGINE_RENDERERIMPL_HPP