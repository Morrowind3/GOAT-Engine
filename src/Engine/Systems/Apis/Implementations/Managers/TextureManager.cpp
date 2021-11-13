#include "TextureManager.hpp"

using namespace Engine;

TextureManager::TextureManager(): _textures { std::make_unique<std::map<std::string,SDL_Texture*>>() } {

}

void TextureManager::store(std::pair<std::string,SDL_Texture*> texture) {
    auto iterator { _textures->find(texture.first) };
    if (iterator == _textures->end()) {
        _textures->insert(texture);
    } else {
        _textures->erase(texture.first);
        _textures->insert(texture);
    }
}

SDL_Texture* TextureManager::get(const std::string& name) {
    return _textures->at(name);
}

void TextureManager::remove(const std::string& name) {
    _textures->erase(name);
}
