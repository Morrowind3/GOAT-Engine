#include "Object_DeleteSaveButton.hpp"
#include "../../../../../../Keys.hpp"
#include "Sprite_DeleteButton.hpp"
#include "Behavior_DeleteSave.hpp"
#include "Sound_Delete.hpp"

Object_DeleteSaveButton::Object_DeleteSaveButton(int saveNumber, Script& loadSavesScript, const Transform& transform, bool active): GameObject(transform, active) {
    tags.insert(std::make_pair(Keys::SAVE_FILE,true)); // Identifiable as part of a save file

    auto& deleteSound = audioSources.insert(std::make_pair(Keys::SAVE_ERASE, Sound_Delete{1, 100, false, true})).first->second;
    buttons.insert(std::make_pair(Keys::SAVE_ERASE, Button{Sprite_DeleteButton(true),
      Rectangle{transform.position, 100, 100},
      std::make_shared<Behavior_DeleteSave>(saveNumber, loadSavesScript, deleteSound, true), true}));
}
