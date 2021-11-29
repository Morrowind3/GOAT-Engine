#include <stdexcept>
#include "AudioManager.hpp"

using namespace Engine;

void AudioManager::storeSample(const std::string& fileName) {
    if (_samples->find(fileName) == _samples->end()) { // Only add a sample if it hasn't been loaded in yet
        Mix_Chunk* sample = Mix_LoadWAV(fileName.c_str());
        if (sample == nullptr) throw std::runtime_error("Sample " + fileName + " not found");
        _samples->insert(std::pair<std::string,Sample>{fileName,Sample{sample}});
    }
}

void AudioManager::storeMusic(const std::string& fileName) {
    if (_music->find(fileName) == _music->end()) { // Only add music if it hasn't been loaded in yet
        Mix_Music* music = Mix_LoadMUS(fileName.c_str());
        if (music == nullptr) throw std::runtime_error("Music " + fileName + " not found");
        _music->insert(std::pair<std::string,Music>{fileName,Music{music}});
    }
}

// Iterator instead of direct access in-case a new object gets spawned and its sample has not been loaded in
const Sample& Engine::AudioManager::getSample(const std::string& fileName) {
    auto iterator = _samples->find(fileName);
    if (iterator == _samples->end()) {
        storeSample(fileName);
        return _samples->at(fileName);
    }
    return iterator->second;
}

// Iterator instead of direct access in-case a new object gets spawned and its music has not been loaded in
const Music& Engine::AudioManager::getMusic(const std::string& fileName) {
    auto iterator = _music->find(fileName);
    if (iterator == _music->end()) {
        storeMusic(fileName);
        return _music->at(fileName);
    }
    return iterator->second;
}

[[maybe_unused]] void AudioManager::removeSample(const std::string& fileName) {
    _samples->erase(fileName);
}

[[maybe_unused]] void AudioManager::removeMusic(const std::string& fileName) {
    _music->erase(fileName);
}

void AudioManager::resetForNextScene() {
    for (auto& sample: *_samples) {
        Mix_FreeChunk(sample.second.audio());
    }
    _samples = std::make_unique<std::map<std::string,Sample>>();
    for (auto& music: *_music) {
        Mix_FreeMusic(music.second.audio());
    }
    _music = std::make_unique<std::map<std::string,Music>>();
}
