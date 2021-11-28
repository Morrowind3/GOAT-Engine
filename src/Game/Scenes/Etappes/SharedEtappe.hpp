#ifndef GOAT_ENGINE_SHAREDETAPPE_HPP
#define GOAT_ENGINE_SHAREDETAPPE_HPP

#include "../../../Engine/API/Scene.hpp"
#include "../../GameObjects/Characters/Player.hpp"

using namespace Engine;

/// Empty etappe with everything needed by every etappe, NOT playable as an etappe on its own!
class SharedEtappe : public Scene {
    public: SharedEtappe(const std::string& etappeKey, Transform playerStartPosition,
        // Level constructor params
        const std::string& fileLocation, int tileSize, int columns, int rows, int scale, int xOffset, int yOffset);
        // TODO: Not sure if this is a good idea, but maybe put a pure virtual constructFromTiled method here to force this to stay abstract
        std::shared_ptr<Player> player;
};


#endif //GOAT_ENGINE_SHAREDETAPPE_HPP
