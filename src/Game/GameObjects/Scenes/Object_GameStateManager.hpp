#ifndef GOAT_ENGINE_OBJECT_GAMESTATEMANAGER_HPP
#define GOAT_ENGINE_OBJECT_GAMESTATEMANAGER_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/SceneManager.hpp"
#include "../Utils/Timer/Object_Timer.hpp"

using namespace Engine;

class Object_GameStateManager : public GameObject {
    public: Object_GameStateManager(const std::shared_ptr<Object_Timer>& timer, bool active);
};


#endif //GOAT_ENGINE_OBJECT_GAMESTATEMANAGER_HPP
