#include "Script.hpp"

using namespace Engine;

Script::Script(bool active) : GameComponent(active) {
}

// Empty methods so that scripts themselves don't need to implement empty methods when not needed

void Script::OnStart() {
}

void Script::OnUpdate(double deltaTime) {
}

void Script::OnDestroy() {
}
