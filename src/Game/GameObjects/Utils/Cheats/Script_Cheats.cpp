#include "Script_Cheats.hpp"

Script_Cheats::Script_Cheats(std::map<std::string, Text>& textObjects, bool active) : Script(active),
                                                                                    _textObjects(textObjects) {}
// ____
//| ~  |
//| `  |-Key
//|____|
void Script_Cheats::onUpdate(double deltaTime) {
    if (_input.getKeyDown(KeyCode::BACKQUOTE)) {
        if (_visible) {
            for (auto &[key, val]: _textObjects) {
                if(std::includes(key.begin(), key.end(), _filterKey.begin(), _filterKey.end())) {
                    val.active = false;
                }
            }
            _visible = false;
        } else {
            for (auto &[key, val]: _textObjects) {
                if(std::includes(key.begin(), key.end(), _filterKey.begin(), _filterKey.end())) {
                    val.active = true;
                }
            }
            _visible = true;
        }
    }
}
