#ifndef GOAT_ENGINE_TEXTUREMANAGER_HPP
#define GOAT_ENGINE_TEXTUREMANAGER_HPP

#include "SDL.h"
#include "Texture.hpp"
#include <map>
#include <memory>
#include <string>

namespace Engine {
    class TextureManager {
        public:
            TextureManager();
            void store(std::string name, SDL_Texture* data);
            const Texture& get(const std::string& name) const;
            void remove(const std::string& name);
        private:
            std::unique_ptr<std::map<std::string,Texture>> _textures;
    };
}

#endif //GOAT_ENGINE_TEXTUREMANAGER_HPP
