#ifndef GOAT_ENGINE_FONT_HPP
#define GOAT_ENGINE_FONT_HPP

#include <SDL_ttf.h>
#include <string>
#include <map>
#include "../../../../../API/GameObjects/Color.hpp"
#include "../Textures/Texture.hpp"

namespace Engine {
    class Font  {
        public:
            Font(std::string fileName, SDL_Renderer* renderer);
            [[nodiscard]] Texture* text(const std::string& text, uint8_t size, Color color);
            ~Font();
            // TODO: Rule of five
        private:
            std::string _fileName;
            std::map<uint8_t,TTF_Font*> _fontSizes;
            SDL_Renderer* _renderer;
    };
}

#endif //GOAT_ENGINE_FONT_HPP
