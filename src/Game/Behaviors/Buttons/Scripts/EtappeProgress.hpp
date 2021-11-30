#ifndef GOAT_ENGINE_ETAPPEPROGRESS_HPP
#define GOAT_ENGINE_ETAPPEPROGRESS_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

// TODO: Persistence with SQLite
class EtappeProgress : public Script {
    public:
        explicit EtappeProgress(bool active);
        void onStart();
    private:
        // Globals
        Globals& _globals = Globals::getInstance();
};


#endif //GOAT_ENGINE_ETAPPEPROGRESS_HPP
