#include "AudioSystem.hpp"

using namespace Engine;

void AudioSystem::onLaunchEngine() {
    _debug.log("Audio system launch");
    _api = &AudioApi::getInstance();
}

void AudioSystem::onLoadScene(std::shared_ptr<Scene> scene) {
    _debug.log("Audio system load");
    _api->resetForNextScene();
    _scene = scene;
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& audioSource : gameObject->audioSources) {
            if (audioSource.second.type == AudioSourceType::SAMPLE) _api->loadSample(audioSource.second.path);
            if (audioSource.second.type == AudioSourceType::MUSIC) _api->loadMusic(audioSource.second.path);
        }
    }
}

void AudioSystem::onFrameTick(double deltaTime) {
    for (auto& gameObject : activeObjects()) {
        for (auto& audioSource : gameObject->audioSources) {
            if (audioSource.second.active && audioSource.second.queueForPlay) {
                if (audioSource.second.type == AudioSourceType::SAMPLE) _api->playSample(audioSource.second.path);
                if (audioSource.second.type == AudioSourceType::MUSIC) _api->playMusic(audioSource.second.path);
                audioSource.second.queueForPlay = false;
            }
        }
    }
}

void AudioSystem::onCloseEngine() {
    _debug.log("Audio system close"); // Empty
}
