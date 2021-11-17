#include "Font.hpp"

using namespace Engine;

Font::Font(std::string fileName, SDL_Renderer* renderer): _renderer{renderer}, _fileName{std::move(fileName)}, _fontSizes{} {
}

// TODO: Find some way to store font textures (findable by all three attributes being the same) so that they don't have to be regenerated
Texture* Font::text(const std::string& text, uint8_t size, Color color) {
    if(_fontSizes.find(size) == _fontSizes.end()) {
        _fontSizes.insert(std::pair<uint8_t,TTF_Font*>{size,TTF_OpenFont(_fileName.c_str(), size)});
    }
    TTF_Font* font = _fontSizes.at(size);
    SDL_Color sdlColor = {color.R, color.G, color.B, color.A};
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), sdlColor);
    return new Texture{SDL_CreateTextureFromSurface(_renderer, surface)};
}

Font::~Font() {
    for(auto& font : _fontSizes) {
        TTF_CloseFont(font.second);
    }
}
