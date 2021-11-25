#include "GameObject.hpp"

using namespace Engine;

GameObject::GameObject(Transform transform, bool active): transform{transform}, active {active},
                                                          behaviors{}, sprites{}, audioSources{}, text{}, collider{active}, rigidBody{0.0f, 0.0f, BodyType::STATIC, false } {}
