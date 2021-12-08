#include "DeleteSaveButton.hpp"
#include "../../../../../../Keys.hpp"
#include "../../../../../../Sprites/Buttons/Sprite_DeleteButton.hpp"

DeleteSaveButton::DeleteSaveButton(int saveNumber, const Transform& transform, bool active): GameObject(transform, active) {
    buttons.insert(std::make_pair(Keys::SAVE_PLAY, Button{Sprite_DeleteButton(true),
      Rectangle{transform.position, 100, 100},
      std::make_shared<Behavior>(false), true})); // TODO: Deletion behavior
}
