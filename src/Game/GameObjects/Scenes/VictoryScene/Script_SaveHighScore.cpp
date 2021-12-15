#include "Script_SaveHighScore.hpp"
#include "../../../Keys.hpp"

Script_SaveHighScore::Script_SaveHighScore(Text& trashText, Text& timeText, Text& scoreText, bool active): Script(active),
    _trashText{trashText}, _timeText{timeText}, _scoreText{scoreText} {
}

// TODO: Edmund passing the line or not should have an impact on the score (finish flag location and line location X)
void Script_SaveHighScore::onStart() {
    // Get required data from globals
    const int saveId = std::stoi(_globals.gameGet(Keys::CURRENT_PLAYER_ID));
    const int etappeId = std::stoi(_globals.gameGet(Keys::CURRENT_ETAPPE));
    const int collectedTrash = std::stoi(_globals.gameGet(Keys::TRASH));
    const int millisecondsElapsed = std::stoi(_globals.gameGet(Keys::TIMER));
    const int remainingHp = std::stoi(_globals.gameGet(Keys::HP));
    const int difficulty = std::stoi(_globals.gameGet(Keys::DIFFICULTY));
    const int finishLocationX = 0, lineLocationX = 0; // TODO: Store and read this

    // Calculate score from data
    const int score = calculateScore(collectedTrash, millisecondsElapsed, remainingHp,
                                     difficulty, finishLocationX, lineLocationX);

    // Update text
    _trashText.text = std::to_string(collectedTrash);
    _timeText.text = _globals.gameGet(Keys::TIMER_TEXT);
    _scoreText.text = std::to_string(score);

    // Update database
    DataModel save = getHighScore(saveId, etappeId);
    save.setValue("Score", std::to_string(score));
    _dataApi.update(save);
}

int Script_SaveHighScore::calculateScore(const int collectedTrash, const int millisecondsElapsed, const int remainingHp,
                                         const int difficulty, const int finishLocationX, const int lineLocationX) const {
    const int trashScore = collectedTrash * 150;
    const int difficultyScore = difficulty * 10;
    const int locationScore = finishLocationX - lineLocationX;
    const double timePenalty = (double)millisecondsElapsed / 100.0;
    const int healthPenalty = (3 - remainingHp) * 300;
    _debug.log("Trash score: " + std::to_string(collectedTrash));
    _debug.log("Difficulty score: " + std::to_string(difficultyScore));
    _debug.log("Location score: " + std::to_string(locationScore));
    _debug.log("Time penalty: " + std::to_string(timePenalty));
    _debug.log("Health penalty: " + std::to_string(healthPenalty));
    return trashScore + difficultyScore + locationScore - timePenalty - healthPenalty;
}

DataModel Script_SaveHighScore::getHighScore(const int saveId, const int etappeId) const {
    const std::string saveIdString = std::to_string(saveId);
    const std::string etappeIdString = std::to_string(etappeId);
    auto highScores = _dataApi.getAll("HighScores");
    for (auto& highScore: highScores) {
        if (saveIdString == highScore.getValue("Players_id") &&
            etappeIdString == highScore.getValue("EtappeNumber")) {
            return highScore;
        }
    }
    throw std::runtime_error("Script_SaveHighScore: high score with save ID " + saveIdString + " and etappe ID " + etappeIdString + " not found");
}
