#include "Behavior.hpp"

using namespace Engine;

Behavior::Behavior(bool active) : GameComponent(active) {
}

void Behavior::OnStart() {
    for(auto& script : scripts) {
        if(script.second->active) script.second->OnStart();
    }
}

void Behavior::OnUpdate(double deltaTime) {
    for(auto& script : scripts) {
        if(script.second->active) script.second->OnUpdate(deltaTime);
    }
}

void Behavior::OnExternalEvent() {
    for(auto& script : scripts) {
        if(script.second->active) script.second->OnExternalEvent();
    }
}

void Behavior::OnDestroy() {
    for(auto& script : scripts) {
        if(script.second->active) script.second->OnDestroy();
    }
}

void Behavior::OnTriggerEnter2D(GameObject& other) {
    for(auto& script : scripts) {
        if(script.second->active) script.second->OnTriggerEnter2D(other);
    }
}

void Behavior::OnTriggerStay2D(GameObject& other) {
    for(auto& script : scripts) {
        if(script.second->active) script.second->OnTriggerStay2D(other);
    }
}

void Behavior::OnTriggerExit2D(GameObject& other) {
    for(auto& script : scripts) {
        if(script.second->active) script.second->OnTriggerExit2D(other);
    }
}
