#include "TextureManager.hpp"

using namespace Engine;

void TextureManager::Store(TypeId id, const Texture& texture) {
    auto iterator { _textures->find(id) };
    if (iterator == _textures->end()) {
        _textures->insert(std::pair<TypeId,Texture>{ id, texture });
    } else {
        _textures->erase(id);
        _textures->insert(std::pair<TypeId,Texture>{ id, texture });
    }
}

Texture TextureManager::Get(TypeId id) {
    return _textures->at(id);
}

void TextureManager::Remove(TypeId id) {
    _textures->erase(id);
}