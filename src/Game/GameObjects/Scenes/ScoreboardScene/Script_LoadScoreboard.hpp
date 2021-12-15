#ifndef GOAT_ENGINE_SCRIPT_LOADSCOREBOARD_HPP
#define GOAT_ENGINE_SCRIPT_LOADSCOREBOARD_HPP

#include "../../../../Engine/API/Scene.hpp"
#include "../../../../Engine/Systems/Apis/DataApi.hpp"
#include "../../../../Engine/Utilities/EngineCalls.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../Helpers/HighScoreKeeper.hpp"

using namespace Engine;

class Script_LoadScoreboard: public Script {
    public:
        /// Used to load scoreboard for one specific etappe
        Script_LoadScoreboard(unsigned short etappeNumber, Text& scoreboardHeader, bool active);
        /// Used to load scoreboard for all etappes
        Script_LoadScoreboard(Text& scoreboardHeader, bool active);
        void onStart() override;
        void onExternalEvent() override;
    private:
        // Utilities
        EngineCalls& _engine = EngineCalls::getInstance();
        DataApi& _data = DataApi::getInstance();
        Globals& _globals = Globals::getInstance();
        // Variables
        std::shared_ptr<Scene> _scene;
        Text& _scoreboardHeader;
        const unsigned short _etappeNumber;
        // Constants
        const int SCOREBOARD_ENTRY_AMOUNT {3};
        const unsigned int SCOREBOARD_ENTRY_HEIGHT {120};
        // Helper methods
        [[nodiscard]] bool isFirstScoreboardCall() const;
        void markAsFirstScoreboardCall();
        void getActiveScene();
        void loadScoreboard();
        void resetScoreboardScene();
        HighScoreKeeper loadScoreboardSpecificEtappe(unsigned short etappeNumber);
        HighScoreKeeper loadScoreboardAllEtappes();
};


#endif //GOAT_ENGINE_SCRIPT_LOADSCOREBOARD_HPP
