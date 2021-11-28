#include "Script.hpp"
#include "../../GameObject.hpp"

using namespace Engine;

Script::Script(bool active) : GameComponent(active) {
}

// Empty methods so that scripts themselves don't need to implement empty methods when not needed
void Script::OnStart() {}
void Script::OnUpdate(double deltaTime) {}
void Script::OnExternalEvent() {}
void Script::OnDestroy() {}
void Script::OnTriggerEnter2D(GameObject& other) {}
void Script::OnTriggerStay2D(GameObject& other) {}
void Script::OnTriggerExit2D(GameObject& other) {}