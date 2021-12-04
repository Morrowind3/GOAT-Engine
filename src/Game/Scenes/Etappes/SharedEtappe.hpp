#ifndef GOAT_ENGINE_SHAREDETAPPE_HPP
#define GOAT_ENGINE_SHAREDETAPPE_HPP

#include "../../../Engine/API/Scene.hpp"
#include "../../../Engine/SceneManager.hpp"
#include "../../GameObjects/Player/Player.hpp"

using namespace Engine;

/// Empty etappe with everything needed by every etappe, NOT playable as an etappe on its own!
class SharedEtappe : public Scene {
    public: SharedEtappe(const std::string& etappeKey, SceneManager& manager,
        // Level constructor params
        const std::string& fileLocation, int tileSize, int columns, int rows, int scale, int xOffset, int yOffset);
    private: friend class MountEverestimateLevelConstructor;
        std::shared_ptr<Player> player;
};


#endif //GOAT_ENGINE_SHAREDETAPPE_HPP
