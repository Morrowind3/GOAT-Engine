#ifndef GOAT_ENGINE_FONT_HPP
#define GOAT_ENGINE_FONT_HPP

#include <SDL_ttf.h>
#include <string>
#include <map>
#include "../../../../../API/GameObjects/Color.hpp"
#include <vector>
#include <memory>
#include <set>
#include <unordered_set>
#include "../Textures/Texture.hpp"

namespace Engine {
    class Font  {
        public:
            Font(std::string fileName, SDL_Renderer* renderer);
            std::shared_ptr<Texture> text(const std::string& text, uint8_t size, Color color);
        private:
            using fontParams = std::tuple<std::string, uint8_t, Color>;
            std::string _fileName;
            std::set<fontParams> _fonts;
            std::map<fontParams, std::shared_ptr<Texture>> _fontTextures;
            std::vector<SDL_Surface*> _surfaceReferences;
            SDL_Renderer* _renderer;
            friend class FontManager;
    };
}

#endif //GOAT_ENGINE_FONT_HPP
