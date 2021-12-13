#ifndef GOAT_ENGINE_BEHAVIOR_ETAPPEMARKER_HPP
#define GOAT_ENGINE_BEHAVIOR_ETAPPEMARKER_HPP

#include "./Object_EtappeMarker.hpp"

using namespace Engine;

class Behavior_EtappeMarker : public Behavior {
    public: Behavior_EtappeMarker(Object_EtappeMarker& etappeMarker, int levelNumber, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_ETAPPEMARKER_HPP
