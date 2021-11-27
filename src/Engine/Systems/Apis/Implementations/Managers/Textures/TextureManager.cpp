#include "TextureManager.hpp"

using namespace Engine;

TextureManager::TextureManager(SDL_Renderer* renderer): _renderer{renderer} {
    resetForNextScene();
}

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

[[maybe_unused]] void TextureManager::remove(const std::string& fileName) {
    _textures->erase(fileName);
}

void TextureManager::resetForNextScene() {
    for (auto& texture: *_textures) {
        SDL_DestroyTexture(texture.second.texture());
    }
    _textures = std::make_unique<std::map<std::string,Texture>>();
}
