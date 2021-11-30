#include "Behavior.hpp"

using namespace Engine;

Behavior::Behavior(bool active) : GameComponent(active) {
}

void Behavior::onStart() {
    for(auto& script : scripts) {
        if(script.second->active) script.second->onStart();
    }
}

void Behavior::onUpdate(double deltaTime) {
    for(auto& script : scripts) {
        if(script.second->active) script.second->onUpdate(deltaTime);
    }
}

void Behavior::onExternalEvent() {
    for(auto& script : scripts) {
        if(script.second->active) script.second->onExternalEvent();
    }
}

void Behavior::onDestroy() {
    for(auto& script : scripts) {
        if(script.second->active) script.second->onDestroy();
    }
}

void Behavior::onTriggerEnter2D(GameObject& other) {
    for(auto& script : scripts) {
        if(script.second->active) script.second->onTriggerEnter2D(other);
    }
}

void Behavior::onTriggerStay2D(GameObject& other) {
    for(auto& script : scripts) {
        if(script.second->active) script.second->onTriggerStay2D(other);
    }
}

void Behavior::onTriggerExit2D(GameObject& other) {
    for(auto& script : scripts) {
        if(script.second->active) script.second->onTriggerExit2D(other);
    }
}
