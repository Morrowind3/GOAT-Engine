#include "Script.hpp"
#include "../../GameObject.hpp"

using namespace Engine;

Script::Script(bool active) : GameComponent(active) {
}

// Empty methods so that scripts themselves don't need to implement empty methods when not needed
void Script::onStart() {}
void Script::onUpdate(double deltaTime) {}
void Script::onExternalEvent() {}
void Script::onDestroy() {}
void Script::onTriggerEnter2D(GameObject& other) {}
void Script::onTriggerStay2D(GameObject& other) {}
void Script::onTriggerExit2D(GameObject& other) {}