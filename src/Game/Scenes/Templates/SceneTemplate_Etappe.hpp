#ifndef GOAT_ENGINE_SCENETEMPLATE_ETAPPE_HPP
#define GOAT_ENGINE_SCENETEMPLATE_ETAPPE_HPP

#include "../../../Engine/API/Scene.hpp"
#include "../../../Engine/SceneManager.hpp"
#include "../../GameObjects/Player/Object_Player.hpp"

using namespace Engine;

/// Empty etappe with everything needed by every etappe, NOT playable as an etappe on its own!
class SceneTemplate_Etappe : public Scene {
    public: SceneTemplate_Etappe(const std::string& etappeKey,
        // Level constructor params
        const std::string& fileLocation, int tileSize, int columns, int rows, int scale, int xOffset, int yOffset);
    private: friend class MountEverestimateLevelConstructor;
        std::shared_ptr<Object_Player> player;
};


#endif //GOAT_ENGINE_SCENETEMPLATE_ETAPPE_HPP
