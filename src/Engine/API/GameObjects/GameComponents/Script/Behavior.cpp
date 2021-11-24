#include "Behavior.hpp"

using namespace Engine;

Behavior::Behavior(bool active) : GameComponent(active), scripts{} {
}

void Behavior::OnStart() {
    for(auto& script : scripts) {
        script->OnStart();
    }
}

void Behavior::OnUpdate(double deltaTime) {
    for(auto& script : scripts) {
        script->OnUpdate(deltaTime);
    }
}

void Behavior::OnExternalEvent() {
    for(auto& script : scripts) {
        script->OnExternalEvent();
    }
}

void Behavior::OnDestroy() {
    for(auto& script : scripts) {
        script->OnDestroy();
    }
}
