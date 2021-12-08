#ifndef GOAT_ENGINE_INCREASEETAPPECOUNTSCRIPT_HPP
#define GOAT_ENGINE_INCREASEETAPPECOUNTSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../../Engine/Systems/Apis/DataApi.hpp"

using namespace Engine;

class IncreaseEtappeCountScript : public Script {
    public:
        explicit IncreaseEtappeCountScript(bool active);
        void onStart();
    private:
        // Utilities
        DataApi& _dataApi = DataApi::getInstance();
        Globals& _globals = Globals::getInstance();
};


#endif //GOAT_ENGINE_INCREASEETAPPECOUNTSCRIPT_HPP
