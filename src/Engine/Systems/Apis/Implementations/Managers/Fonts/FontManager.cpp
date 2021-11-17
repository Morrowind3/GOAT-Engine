#include "FontManager.hpp"

using namespace Engine;

FontManager::FontManager() : _fonts(std::make_unique<std::map<std::string, TTF_Font*>>()) {}

void FontManager::store(const std::string& name, const std::string& path, const Uint8 size) {
    if (_fonts->find(name) == _fonts->end()) { // if not already stored
        TTF_Font* font = TTF_OpenFont(path.c_str(), size);
        _fonts->insert(std::pair<std::string, TTF_Font*>{name, font});
    }
}

TTF_Font* FontManager::get(const std::string& name) const {
    return _fonts->at(name);
}

void FontManager::remove(const std::string& name) {
    TTF_CloseFont(_fonts->at(name));
    _fonts->erase(name);
}