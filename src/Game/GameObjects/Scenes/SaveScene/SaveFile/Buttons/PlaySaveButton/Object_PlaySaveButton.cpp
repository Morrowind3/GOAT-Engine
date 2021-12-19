#include "Object_PlaySaveButton.hpp"
#include "../../../../../../Keys.hpp"
#include "Sprite_PlayButton.hpp"
#include "Behavior_PlaySave.hpp"

Object_PlaySaveButton::Object_PlaySaveButton(int saveNumber, const Transform& transform, bool active): GameObject(transform, active) {
    tags.insert(std::make_pair(Keys::SAVE_FILE,true)); // Identifiable as part of a save file

    buttons.insert(std::make_pair(Keys::SAVE_PLAY, Button{Sprite_PlayButton(true),
      Rectangle{transform.position, 100, 100},
      std::make_shared<Behavior_PlaySave>(saveNumber,true), true}));
}
