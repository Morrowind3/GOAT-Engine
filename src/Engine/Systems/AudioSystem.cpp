//
// Created by MDstu on 14/11/2021.
//

#include "AudioSystem.hpp"
#include "../Systems/Apis/AudioApi.hpp."

using namespace Engine;

AudioSystem::AudioSystem(const Scene *scene) : System(scene) {

}

void AudioSystem::OnInit() {

}

void AudioSystem::OnUpdate() {

}

void AudioSystem::OnDestroy() {
    AudioApi::End();
}



