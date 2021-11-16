#include "Scene.hpp"

using namespace Engine;

Scene::Scene(std::string name) : name(std::move(name)), gameObjects{} {
}
