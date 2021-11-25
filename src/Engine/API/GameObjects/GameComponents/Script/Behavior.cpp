#include "Behavior.hpp"

using namespace Engine;

Behavior::Behavior(bool active) : GameComponent(active) {
}

void Behavior::OnStart() {
    for(auto& script : scripts) {
        script.second->OnStart();
    }
}

void Behavior::OnUpdate(double deltaTime) {
    for(auto& script : scripts) {
        script.second->OnUpdate(deltaTime);
    }
}

void Behavior::OnExternalEvent() {
    for(auto& script : scripts) {
        script.second->OnExternalEvent();
    }
}

void Behavior::OnDestroy() {
    for(auto& script : scripts) {
        script.second->OnDestroy();
    }
}
