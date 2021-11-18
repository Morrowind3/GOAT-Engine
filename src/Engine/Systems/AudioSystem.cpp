#include "AudioSystem.hpp"

using namespace Engine;

AudioSystem::AudioSystem(const Scene* scene) : System(scene), _api{AudioApi::getInstance()} {
}

void AudioSystem::OnInit() {
    for (auto& gameObject : _scene->gameObjects) {
        for (auto& audioSource : gameObject->audioSources) {
            if (audioSource.second.type == AudioSourceType::SAMPLE) _api.LoadSample(audioSource.second.path);
            if (audioSource.second.type == AudioSourceType::MUSIC)  _api.LoadMusic(audioSource.second.path);
        }
    }
}

void AudioSystem::OnUpdate(double deltaTime) {
    for (auto& gameObject : activeObjects()) {
        for (auto& audioSource : gameObject->audioSources) {
            if (audioSource.second.active && audioSource.second.queueForPlay) {
                if (audioSource.second.type == AudioSourceType::SAMPLE) _api.PlaySample(audioSource.second.path);
                if (audioSource.second.type == AudioSourceType::MUSIC)  _api.PlayMusic(audioSource.second.path);
                audioSource.second.queueForPlay = false;
            }
        }
    }
}

void AudioSystem::OnDestroy() {
}



