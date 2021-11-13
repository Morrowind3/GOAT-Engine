#ifndef GOAT_ENGINE_TEXTUREMANAGER_HPP
#define GOAT_ENGINE_TEXTUREMANAGER_HPP

#include "SDL.h"
#include <map>
#include <memory>

namespace Engine {
    class TextureManager {
        public:
            TextureManager();
            void store(std::pair<std::string,SDL_Texture*> texture);
            SDL_Texture* get(const std::string& name);
            void remove(const std::string& name);
        private:
            std::unique_ptr<std::map<std::string,SDL_Texture*>> _textures;
    };
}

#endif //GOAT_ENGINE_TEXTUREMANAGER_HPP
