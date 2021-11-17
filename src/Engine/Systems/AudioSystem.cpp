#include "AudioSystem.hpp"
#include "../Systems/Apis/AudioApi.hpp"

using namespace Engine;

AudioSystem::AudioSystem(const Scene *scene) : System(scene) {

}

void AudioSystem::OnInit() {
    AudioApi::Start();

    /* TODO: Used for testing */
//    AudioApi::Play(AudioApi::CreateClip("Bleathing.ogg"), false, 1, 100.0);
}

void AudioSystem::OnUpdate(double deltaTime) {
    // TODO: Logic here
}

void AudioSystem::OnDestroy() {
    AudioApi::End();
}



