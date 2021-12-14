#ifndef GOAT_ENGINE_OBJECT_ETAPPEMARKER_HPP
#define GOAT_ENGINE_OBJECT_ETAPPEMARKER_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_EtappeMarker: public GameObject {
    public: Object_EtappeMarker(const std::string& etappeKey, int etappeNumber, unsigned short height, Transform transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_ETAPPEMARKER_HPP
