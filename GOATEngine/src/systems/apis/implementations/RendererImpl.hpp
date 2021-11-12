#ifndef GOATENGINE_RENDERERIMPL_HPP
#define GOATENGINE_RENDERERIMPL_HPP

#include <memory>
#include <map>
#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "../../../core/Base.hpp"
#include "../../../components/GameObject.hpp"
#include "../../../resources/Texture.hpp"
#include "../../../managers/TextureManager.hpp"
#include "../../../components/Transform.hpp"

namespace Engine {
    class RendererImpl {
        public:
            RendererImpl();
            [[nodiscard]] Texture loadTexture(const std::string &fileName);
            void beginRenderTick();
            void drawTexture(const Texture& texture, const Transform& transform);
            void endRenderTick();
            void end();

        private:
            int _sdlStatus;
            std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> _window;
            std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)> _renderer;
            std::unique_ptr<TextureManager> _textures;
    };
}

#endif //GOATENGINE_RENDERERIMPL_HPP
