#ifndef GOAT_ENGINE_TEXTUREMANAGER_HPP
#define GOAT_ENGINE_TEXTUREMANAGER_HPP

#include "SDL_image.h"
#include "Texture.hpp"
#include "../../../../../API/GameObjects/Rectangle.hpp"
#include "../../../../../API/GameObjects/Color.hpp"

#include <map>
#include <memory>
#include <string>

namespace Engine {
    class TextureManager {
        public:
            explicit TextureManager(SDL_Renderer* renderer);
            void store(const std::string& fileName);
            [[nodiscard]] const Texture& get(const std::string& fileName);
            [[maybe_unused]] void remove(const std::string& fileName);
            void resetForNextScene();
        private:
            std::unique_ptr<std::map<std::string,Texture>> _textures = std::make_unique<std::map<std::string,Texture>>();
            SDL_Renderer* _renderer;
    };
}

#endif //GOAT_ENGINE_TEXTUREMANAGER_HPP
