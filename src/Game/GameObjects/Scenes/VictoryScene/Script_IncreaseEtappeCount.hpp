#ifndef GOAT_ENGINE_SCRIPT_INCREASEETAPPECOUNT_HPP
#define GOAT_ENGINE_SCRIPT_INCREASEETAPPECOUNT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../../Engine/Systems/Apis/DataApi.hpp"

using namespace Engine;

class Script_IncreaseEtappeCount : public Script {
    public:
        explicit Script_IncreaseEtappeCount(bool active);
        void onStart();
    private:
        // Utilities
        DataApi& _dataApi = DataApi::getInstance();
        Globals& _globals = Globals::getInstance();
};


#endif //GOAT_ENGINE_SCRIPT_INCREASEETAPPECOUNT_HPP
