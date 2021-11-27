#ifndef GOAT_ENGINE_SHAREDETAPPE_HPP
#define GOAT_ENGINE_SHAREDETAPPE_HPP

#include "../../../Engine/API/Scene.hpp"
#include "../../GameObjects/Characters/Player.hpp"
#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

/// Empty etappe with everything needed by every etappe, NOT playable as an etappe on its own!
class SharedEtappe : public Scene {
    public: explicit SharedEtappe(const std::string& etappeKey, Transform playerStartPosition, SceneManager& sceneManager);
    // TODO: Not sure if this is a good idea, but maybe put a pure virtual constructFromTiled method here to force this to stay abstract
protected:
    std::shared_ptr<Player> _player;
    SceneManager& _sceneManager;
};


#endif //GOAT_ENGINE_SHAREDETAPPE_HPP
