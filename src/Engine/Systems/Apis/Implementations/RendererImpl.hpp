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
            RendererImpl(const std::string& name, const std::string& iconPath, const std::string& cursor);
            void initialize();
            void setViewPort(Point dimensions);
            void loadTexture(const std::string& fileName);
            void loadFont(const std::string& fileName);
            void beginRenderTick();
            void drawTexture(const std::string& texture, const std::shared_ptr<Transform>& location);
            void drawText(const std::string& text, uint8_t size, Color color, const std::string& fontName, const std::shared_ptr<Transform>& transform);
            void endRenderTick();
            void resetForNextScene();
            void end();
        private:
            int _sdlStatus;
            bool _resizeForFirstSceneHasTakenPlace {false};
            std::string _name, _iconPath, _cursor; // Initialization parameters
            std::unique_ptr<TextureManager> _textures = std::make_unique<TextureManager>(_renderer.get());
            std::unique_ptr<FontManager> _fonts = std::make_unique<FontManager>(_renderer.get());
            std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> _window;
            std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)> _renderer;
            std::vector<std::pair<Transform, const Texture*>> _tickTextureCache;
    };
}

#endif //GOAT_ENGINE_RENDERERIMPL_HPP