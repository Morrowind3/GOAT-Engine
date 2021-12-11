#ifndef GOAT_ENGINE_ETAPPEMARKER_HPP
#define GOAT_ENGINE_ETAPPEMARKER_HPP

#include "../../../../Engine/SceneManager.hpp"

using namespace Engine;

class EtappeMarker: public GameObject {
    public: EtappeMarker(const std::string& levelKey, int levelNumber, unsigned short height, Transform transform, bool active);
};


#endif //GOAT_ENGINE_ETAPPEMARKER_HPP
