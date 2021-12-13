#include "Object_SaveFile.hpp"
#include "../../../../Keys.hpp"
#include "../../../Player/Sprites/Sprite_PlayerWin.hpp"
#include "../../../Player/Sprites/Sprite_PlayerFront.hpp"

Object_SaveFile::Object_SaveFile(int saveNumber, int currentHeight, int mountEverestHeight, int score, const Transform& transform, bool active): GameObject(transform,active) {
    tags.insert(std::make_pair(Keys::SAVE_FILE,true)); // Identifiable as save file

    // Save file avatar (Edmund)
    if (currentHeight >= mountEverestHeight) { // All etappes unlocked avatar
        sprites.insert(std::make_pair(Keys::SAVE_AVATAR, Sprite_PlayerWin(true)));
    } else { // Normal avatar
        sprites.insert(std::make_pair(Keys::SAVE_AVATAR, Sprite_PlayerFront(true)));
    }

    // Save file identifier text
    Transform saveFileIdTransform {transform};
    saveFileIdTransform.scaleWidth = saveFileIdTransform.scaleHeight /= 1.5;
    saveFileIdTransform.position.x += 100;
    saveFileIdTransform.position.y += 10;
    text.insert(std::make_pair(Keys::SAVE_ID, Text {"Save " + std::to_string(saveNumber),
        "Fonts/Kenney_Thick.ttf",24, Color{0,0,0,255}, saveFileIdTransform, true}));

    // Unlocked text
    Transform unlockedTransform {transform};
    unlockedTransform.scaleWidth = unlockedTransform.scaleHeight /= 3.0;
    unlockedTransform.position.x += 450;
    text.insert(std::make_pair(Keys::SAVE_UNLOCKED, Text {"Ascended " + std::to_string(currentHeight) + "m",
        "Fonts/Kenney_Thick.ttf",24, Color{0,0,0,255}, unlockedTransform, true}));

    // Score text
    Transform scoreTransform {unlockedTransform};
    scoreTransform.position.y += 50;
    text.insert(std::make_pair(Keys::SAVE_SCORE, Text {"Total score " + std::to_string(score),
        "Fonts/Kenney_Thick.ttf",24, Color{0,0,0,255}, scoreTransform, true}));
}
