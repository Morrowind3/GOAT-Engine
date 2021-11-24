#ifndef GOAT_ENGINE_RENDERERIMPL_HPP
#define GOAT_ENGINE_RENDERERIMPL_HPP

#include <memory>
#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "../../../API/GameObjects/GameObject.hpp"
#include "Managers/Textures/Texture.hpp"
#include "../../../API/GameObjects/Transform.hpp"
#include "Managers/Textures/TextureManager.hpp"
#include "Managers/Fonts/FontManager.hpp"

namespace Engine {
    class RendererImpl {
        public:
            RendererImpl(const std::string& name, std::string& iconPath, std::string& cursor);
            void LoadTexture(const std::string& fileName);
            void LoadFont(const std::string& fileName);
            void BeginRenderTick();
            void DrawTexture(const std::string& texture, const Transform& location);
            void DrawText(const std::string& text, uint8_t size, Color color, const std::string& fontName, const Transform& transform);
            void EndRenderTick();
            void End();

        private:
            int _sdlStatus;
            std::unique_ptr<TextureManager> _textures;
            std::unique_ptr<FontManager> _fonts;
            std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> _window;
            std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)> _renderer;
            std::vector<std::pair<const Transform*, const Texture*>> _tickTextureCache;
    };
}

#endif //GOAT_ENGINE_RENDERERIMPL_HPP