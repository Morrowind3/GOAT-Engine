#include "TextureManager.hpp"

using namespace Engine;

TextureManager::TextureManager(): _textures { std::make_unique<std::map<std::string,Texture>>() } {

}

void TextureManager::store(std::string name, SDL_Texture* data) {
    std::pair<std::string,Texture> texture { name, Texture{data} };
    auto iterator { _textures->find(texture.first) };
    if (iterator == _textures->end()) {
        _textures->insert(texture);
    } else {
        _textures->erase(texture.first);
        _textures->insert(texture);
    }
}

const Texture& TextureManager::get(const std::string& name) const {
    return _textures->at(name);
}

void TextureManager::remove(const std::string& name) {
    _textures->erase(name);
}
