#ifndef GOAT_ENGINE_SCRIPT_SAVEHIGHSCORE_HPP
#define GOAT_ENGINE_SCRIPT_SAVEHIGHSCORE_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../../Engine/Systems/Apis/DataApi.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp"

using namespace Engine;

class Script_SaveHighScore: public Script {
    public:
        explicit Script_SaveHighScore(Text& trashText, Text& timeText, Text& scoreText, bool active);
        void onStart() override;
    private:
        // Utilities
        DataApi& _dataApi = DataApi::getInstance();
        Globals& _globals = Globals::getInstance();
        Debug& _debug = Debug::getInstance();
        // Variables
        Text& _trashText,& _timeText,& _scoreText;
        // Constants
        const int INITIAL_HIGH_SCORE {1000};
        // Helper methods
        [[nodiscard]] int calculateScore(int collectedTrash, int millisecondsElapsed, int remainingHp,
                                         int finishLocationX, int lineLocationX) const;
        [[nodiscard]] DataModel getHighScore(int saveId, int etappeId) const;
};


#endif //GOAT_ENGINE_SCRIPT_SAVEHIGHSCORE_HPP
