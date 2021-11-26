#include "Globals.hpp"

using namespace Engine;

void Globals::sceneReset() {
    _sceneGlobals = std::make_unique<std::map<std::string,std::string>>();
}

void Globals::sceneStore(const std::string& key, const std::string& value) {
    auto result = _sceneGlobals->find(key);
    if (result != _sceneGlobals->end()) {
        _sceneGlobals->erase(key);
    }
    _sceneGlobals->insert(std::make_pair(key, value));
}

bool Globals::sceneExists(const std::string& key) const {
    return _sceneGlobals->find(key) != _sceneGlobals->end();
}

std::string Globals::sceneGet(const std::string& key) const {
    auto result = _sceneGlobals->find(key);
    if (result != _sceneGlobals->end()) {
        return result->second;
    }
    throw std::runtime_error("The following key was not found in scene globals: " + key);
}

[[maybe_unused]] void Globals::sceneRemove(const std::string& key) {
    _sceneGlobals->erase(key);
}

// ------------------------------------------------------------------------

void Globals::gameStore(const std::string& key, const std::string& value) {
    auto result = _gameGlobals->find(key);
    if (result != _gameGlobals->end()) {
        _gameGlobals->erase(key);
    }
    _gameGlobals->insert(std::make_pair(key, value));
}

bool Globals::gameExists(const std::string& key) const {
    return _gameGlobals->find(key) != _gameGlobals->end();
}

std::string Globals::gameGet(const std::string& key) const {
    auto result = _gameGlobals->find(key);
    if (result != _gameGlobals->end()) {
        return result->second;
    }
    throw std::runtime_error("The following key was not found in game globals: " + key);
}

[[maybe_unused]] void Globals::gameRemove(const std::string& key) {
    _gameGlobals->erase(key);
}
