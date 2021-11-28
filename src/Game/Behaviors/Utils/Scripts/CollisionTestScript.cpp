#include "CollisionTestScript.hpp"

CollisionTestScript::CollisionTestScript(bool active) : Script(active) {
}

void CollisionTestScript::onTriggerEnter2D(GameObject& other) {
    _debug.log("Collision test: on trigger enter 2D => " + std::to_string((int)&other));
}

void CollisionTestScript::onTriggerStay2D(GameObject& other) {
    _debug.log("Collision test: on trigger stay 2D => " + std::to_string((int)&other));
}

void CollisionTestScript::onTriggerExit2D(GameObject& other) {
    _debug.log("Collision test: on trigger exit 2D => " + std::to_string((int)&other));
}
