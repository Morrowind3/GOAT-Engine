#include "CheatsScript.hpp"

CheatsScript::CheatsScript(std::map<std::string, Text>& textObjects, bool active) : Script(active),
                                                                                    _textObjects(textObjects) {}

void CheatsScript::onUpdate(double deltaTime) {
    if (_input.getKeyDown(KeyCode::ESCAPE)) {
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
