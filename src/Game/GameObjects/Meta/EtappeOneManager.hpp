#ifndef GOAT_ENGINE_ETAPPEONEMANAGER_HPP
#define GOAT_ENGINE_ETAPPEONEMANAGER_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

namespace ETAPPE_ONE { // TODO: To keys.hpp
    const std::string BACKGROUND = "Background";
    const std::string SNOWSTORM = "Snowstorm";
}

class EtappeOneManager : public GameObject {
    public: EtappeOneManager(Transform transform, bool active);
};

#endif //GOAT_ENGINE_ETAPPEONEMANAGER_HPP
