#include "GameObject.hpp"

using namespace Engine;

GameObject::GameObject(Transform transform, bool active): transform{transform}, active {active},
                                                          behaviors{}, sprites{} {
}
