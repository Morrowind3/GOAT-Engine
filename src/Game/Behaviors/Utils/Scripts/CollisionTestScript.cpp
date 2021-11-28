#include "CollisionTestScript.hpp"

CollisionTestScript::CollisionTestScript(bool active) : Script(active) {
}

void CollisionTestScript::OnTriggerEnter2D(GameObject& other) {
    _debug.log("Collision test: on trigger enter 2D => " + std::to_string((int)&other));
}

void CollisionTestScript::OnTriggerStay2D(GameObject& other) {
    _debug.log("Collision test: on trigger stay 2D => " + std::to_string((int)&other));
}

void CollisionTestScript::OnTriggerExit2D(GameObject& other) {
    _debug.log("Collision test: on trigger exit 2D => " + std::to_string((int)&other));
}
