#include "SaveFile.hpp"
#include "../../../../Keys.hpp"
#include "../../../../Sprites/Player/Sprite_PlayerWin.hpp"
#include "../../../../Sprites/Player/Sprite_PlayerFront.hpp"

SaveFile::SaveFile(int saveNumber, int currentHeight, int mountEverestHeight, int score, Transform transform, bool active): GameObject(transform,active) {
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
    Transform unlockedTransform {saveFileIdTransform};
    unlockedTransform.position.x += 100;
    text.insert(std::make_pair(Keys::SAVE_ID, Text {"Ascended " + std::to_string(currentHeight) + "m",
        "Fonts/Kenney_Thick.ttf",12, Color{0,0,0,255}, unlockedTransform, true}));

    // Score text
    Transform scoreTransform {unlockedTransform};
    scoreTransform.position.y += 50;
    text.insert(std::make_pair(Keys::SAVE_ID, Text {"Total score " + std::to_string(score),
        "Fonts/Kenney_Thick.ttf",12, Color{0,0,0,255}, scoreTransform, true}));

    // Play button

    // Delete button

}
