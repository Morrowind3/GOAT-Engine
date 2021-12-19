#include "Object_ScoreboardEntry.hpp"
#include "../../../../Keys.hpp"
#include "../../../Player/Sprites/Sprite_PlayerWin.hpp"
#include "../../../Player/Sprites/Sprite_PlayerFront.hpp"

Object_ScoreboardEntry::Object_ScoreboardEntry(unsigned int saveNumber, unsigned int score, bool isWinner, const Transform& transform, bool active):
GameObject(transform, active) {
    tags.insert(std::make_pair(Keys::SCOREBOARD_ENTRY, true)); // Identifyable as scoreboard entry

    // Scoreboard avatar (Edmund)
    if (isWinner) { // The winning scoreboard entry has the winning sprite
        sprites.insert(std::make_pair(Keys::_, Sprite_PlayerWin(true)));
    } else { // Normal avatar
        sprites.insert(std::make_pair(Keys::_, Sprite_PlayerFront(true)));
    }

    // Scoreboard entry text
    Transform scoreboardEntry {transform};
    scoreboardEntry.scaleWidth = scoreboardEntry.scaleHeight /= 1.5;
    scoreboardEntry.position.x += 100;
    scoreboardEntry.position.y += 25;
    text.insert(std::make_pair(Keys::_, Text {"Save " + std::to_string(saveNumber) + " - Score " + std::to_string(score),
        "Fonts/Kenney_Thick.ttf", 16, Color{0,0,0,255}, scoreboardEntry, true}));
}
