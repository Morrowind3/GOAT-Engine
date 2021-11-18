#include "TextureManager.hpp"

using namespace Engine;

TextureManager::TextureManager(SDL_Renderer* renderer): _renderer{renderer}, _textures{ std::make_unique<std::map<std::string,Texture>>() } {

}

// TODO: Throw on image not found
void TextureManager::store(const std::string& fileName) {
    if (_textures->find(fileName) == _textures->end()) { // Only add a texture if it hasn't been loaded in yet
        SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
        SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
        _textures->insert(std::pair<std::string,Texture>{fileName, Texture{texture}});
    }
}

const Texture& TextureManager::get(const std::string& fileName) const {
    return _textures->at(fileName);
}

void TextureManager::remove(const std::string& fileName) {
    _textures->erase(fileName);
}
