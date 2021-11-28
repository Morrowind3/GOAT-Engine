#ifndef GOAT_ENGINE_FONTMANAGER_HPP
#define GOAT_ENGINE_FONTMANAGER_HPP

#include "SDL.h"
#include "SDL_ttf.h"
#include "Font.hpp"
#include <string>
#include <map>
#include <memory>

namespace Engine {
    class FontManager {
        public:
            explicit FontManager(SDL_Renderer* renderer);
            void store(const std::string& fileName);
            [[nodiscard]] Font& get(const std::string& fileName) const;
            [[maybe_unused]] void remove(const std::string& fileName);
            void resetForNextScene();
        private:
            std::unique_ptr<std::map<std::string,Font>> _fonts = std::make_unique<std::map<std::string, Font>>();
            SDL_Renderer* _renderer;
    };
}

#endif //GOAT_ENGINE_FONTMANAGER_HPP
