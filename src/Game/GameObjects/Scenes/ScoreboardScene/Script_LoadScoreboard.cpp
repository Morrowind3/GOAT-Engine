#include "Script_LoadScoreboard.hpp"
#include "../../../Keys.hpp"

Script_LoadScoreboard::Script_LoadScoreboard(unsigned short etappeNumber, Text& scoreboardHeader, bool active):
        Script(active), _etappeNumber{etappeNumber}, _scoreboardHeader{scoreboardHeader} {
}

Script_LoadScoreboard::Script_LoadScoreboard(Text& scoreboardHeader, bool active):
        Script_LoadScoreboard(0, scoreboardHeader, active) {
}

/// This gets run if no scoreboard exists yet
void Script_LoadScoreboard::onStart() {
    if (isFirstScoreboardCall()) {
        markAsFirstScoreboardCall();
        getActiveScene();
        loadScoreboard();
    }
}

/// This gets run when the player presses the button to load this
void Script_LoadScoreboard::onExternalEvent() {
    getActiveScene();
    resetScoreboardScene();
    loadScoreboard();
}

bool Script_LoadScoreboard::isFirstScoreboardCall() const {
    return !_globals.sceneExists(Keys::SCOREBOARD_INITIAL_LOAD);
}

void Script_LoadScoreboard::markAsFirstScoreboardCall() {
    _globals.sceneStore(Keys::SCOREBOARD_INITIAL_LOAD, Keys::TRUE);
}

void Script_LoadScoreboard::getActiveScene() {
    _scene = _engine.getScene();
}

void Script_LoadScoreboard::loadScoreboard() {
    // If etappe number is zero (set by all etappes constructor), load scoreboard for all etappes
    HighScoreKeeper highScores = _etappeNumber == 0
            ? loadScoreboardAllEtappes()
            : loadScoreboardSpecificEtappe(_etappeNumber);
    auto topHighScores = highScores.getTopScores();
    // TODO: Place high scores in scene
    for (auto& highScore: topHighScores) {
        Debug::getInstance().log(std::to_string(highScore.first) + "|" + std::to_string(highScore.second));
    }
}

void Script_LoadScoreboard::resetScoreboardScene() {
    for (auto& gameObject: _scene->gameObjects) {
        if (gameObject->hasTag(Keys::SCOREBOARD_ENTRY)) gameObject->queueForDestruction = true;
    }
}

HighScoreKeeper Script_LoadScoreboard::loadScoreboardSpecificEtappe(unsigned short etappeNumber) {
    _scoreboardHeader.text = " Scoreboard etappe " + std::to_string(etappeNumber);

    HighScoreKeeper highScoreKeeper {SCOREBOARD_ENTRY_AMOUNT};
    auto highScores = _data.getAll("HighScores", "EtappeNumber", false);
    for (auto& highScore: highScores) {
        // Only work with the specified etappe
        unsigned short highScoreEtappe = std::stoi(highScore.getValue("EtappeNumber"));
        if (highScoreEtappe != etappeNumber) continue;

        unsigned int player = std::stoi(highScore.getValue("Players_id"));
        unsigned int score = std::stoi(highScore.getValue("Score"));
        highScoreKeeper.addScore(player, score);
    }
    return highScoreKeeper;
}

HighScoreKeeper Script_LoadScoreboard::loadScoreboardAllEtappes() {
    _scoreboardHeader.text = "Scoreboard all ettapes";

    HighScoreKeeper highScoreKeeper {SCOREBOARD_ENTRY_AMOUNT};
    auto highScores = _data.getAll("HighScores");
    for (auto& highScore: highScores) {
        unsigned int player = std::stoi(highScore.getValue("Players_id"));
        unsigned int score = std::stoi(highScore.getValue("Score"));
        highScoreKeeper.addScore(player, score);
    }
    return highScoreKeeper;
}
