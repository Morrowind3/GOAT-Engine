#include "Font.hpp"
using namespace Engine;

Font::Font(std::string fileName, SDL_Renderer* renderer): _renderer{renderer}, _fileName{std::move(fileName)} {
}

std::shared_ptr<Texture> Font::text(const std::string& text, uint8_t size, Color color) {
    fontParams combination = std::make_tuple(text, size, color);
    auto setMatched = _fonts.find(combination);
    if(setMatched == _fonts.end()){
        _fonts.insert(std::make_tuple(text, size, color));
    } else {
        return _fontTextures.find(*setMatched)->second;
    }

    TTF_Font* font = TTF_OpenFont(_fileName.c_str(), size);
    SDL_Color sdlColor = {color.R, color.G, color.B, color.A};
    _surfaceReferences.emplace_back(TTF_RenderText_Blended(font, text.c_str(), sdlColor));

    auto texture = std::make_shared<Texture>(SDL_CreateTextureFromSurface(_renderer, _surfaceReferences.back()));
    _fontTextures.emplace(combination, texture);
    return texture;
}

