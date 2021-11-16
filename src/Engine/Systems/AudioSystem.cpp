//
// Created by MDstu on 14/11/2021.
//

#include "AudioSystem.hpp"
#include "../Systems/Apis/AudioApi.hpp."
#include <iostream>
using namespace Engine;

AudioSystem::AudioSystem(const Scene *scene) : System(scene) {

}

void AudioSystem::OnInit() {
    AudioApi::Start();

    /* Used for testing */
    // AudioApi::Play(AudioApi::CreateClip(<Path to a .wav file>), false, 1, 100.0);
}

void AudioSystem::OnUpdate() {
}

void AudioSystem::OnDestroy() {
    AudioApi::End();
}



