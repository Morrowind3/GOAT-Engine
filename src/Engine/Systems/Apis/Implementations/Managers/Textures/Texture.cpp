#include "Texture.hpp"

using namespace Engine;

Texture::Texture(SDL_Texture* texture): _texture{texture} {
    int width, height;
    SDL_QueryTexture(_texture, nullptr, nullptr, &width, &height);
    _width = width;
    _height = height;
}

SDL_Texture* Texture::texture() const {
    return _texture;
}

int Texture::width() const {
    return _width;
}

int Texture::height() const {
    return _height;
}

Texture::~Texture() {
//    SDL_DestroyTexture(_texture); // TODO: This destroys the game
}
