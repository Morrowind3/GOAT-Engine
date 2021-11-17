#include "FontManager.hpp"

using namespace Engine;

FontManager::FontManager(SDL_Renderer* renderer) : _renderer{renderer}, _fonts(std::make_unique<std::map<std::string, Font>>()) {}

void FontManager::store(const std::string& fileName) {
    if (_fonts->find(fileName) == _fonts->end()) { // If not already stored
        _fonts->insert(std::make_pair(fileName,Font{fileName,_renderer}));
    }
}

Font& FontManager::get(const std::string& fileName) const {
    return _fonts->at(fileName);
}

void FontManager::remove(const std::string& name) {
    _fonts->erase(name);
}
