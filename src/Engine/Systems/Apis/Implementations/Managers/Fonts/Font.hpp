#ifndef GOAT_ENGINE_FONT_HPP
#define GOAT_ENGINE_FONT_HPP

#include <SDL_ttf.h>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <set>
#include <unordered_set>
#include "../../../../../API/GameObjects/GameComponents/Render/Color.hpp"
#include "../Textures/Texture.hpp"

namespace Engine {
    class Font  {
        public:
            Font(std::string fileName, SDL_Renderer* renderer);
            std::shared_ptr<Texture>  text(const std::string& text, uint8_t size, Color color);
            // TODO: Rule of five
        private:
        using fontParams = std::tuple<std::string, uint8_t, Color>;
            std::string _fileName;
            std::set<fontParams> _fonts;
            std::map<fontParams, std::shared_ptr<Texture>> _fontTextures;
            std::vector<SDL_Surface*> _surfaceReferences;
            SDL_Renderer* _renderer;
    };
}

#endif //GOAT_ENGINE_FONT_HPP
