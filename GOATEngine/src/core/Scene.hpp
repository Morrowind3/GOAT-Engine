#ifndef GOATENGINE_SCENE_HPP
#define GOATENGINE_SCENE_HPP

#include "Base.hpp"
#include "GameObject.hpp"

#include <map>

class Scene {
private:
    size_t sceneId;
    std::map <size_t, GameObject> registry{};
    size_t idCounter{1};

public:
    Scene(size_t id) : sceneId(id) {};

    size_t getId();

    GameObject getGameObject(size_t id);

    void addGameObject(GameObject gameObject);
};

#endif //GOATENGINE_SCENE_HPP
