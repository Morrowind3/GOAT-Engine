#include <stdexcept>
#include "AudioManager.hpp"

using namespace Engine;

AudioManager::AudioManager():
    _samples{std::make_unique<std::map<std::string,Sample>>()},
    _music{std::make_unique<std::map<std::string,Music>>()} {
}

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

const Sample& Engine::AudioManager::getSample(const std::string& fileName) const {
    return _samples->at(fileName);
}

const Music& Engine::AudioManager::getMusic(const std::string& fileName) const {
    return _music->at(fileName);
}

void AudioManager::removeSample(const std::string& fileName) {
    _samples->erase(fileName);
}

void AudioManager::removeMusic(const std::string& fileName) {
    _music->erase(fileName);
}
