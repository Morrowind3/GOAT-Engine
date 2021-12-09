#include "DeleteSaveButton.hpp"
#include "../../../../../../Keys.hpp"
#include "../../../../../../Sprites/Buttons/Sprite_DeleteButton.hpp"
#include "DeleteSaveBehavior.hpp"
#include "../../../../../../AudioSources/Sounds/Menus/Sound_Delete.hpp"

DeleteSaveButton::DeleteSaveButton(int saveNumber, Script& loadSavesScript, const Transform& transform, bool active): GameObject(transform, active) {
    tags.insert(std::make_pair(Keys::SAVE_FILE,true)); // Identifiable as part of a save file

    auto& deleteSound = audioSources.insert(std::make_pair(Keys::SAVE_ERASE, Sound_Delete{1, 100, false, true})).first->second;
    buttons.insert(std::make_pair(Keys::SAVE_ERASE, Button{Sprite_DeleteButton(true),
      Rectangle{transform.position, 100, 100},
      std::make_shared<DeleteSaveBehavior>(saveNumber, loadSavesScript, deleteSound, true), true}));
}
