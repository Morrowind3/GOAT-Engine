//
// Created by Stijn van Loon on 27-11-2021.
//

#include "CheatsScript.hpp"

#include <utility>

CheatsScript::CheatsScript(std::map<std::string, Text>& textObjects, bool active) : Script(active),
                                                                                    _textObjects(textObjects) {}

void CheatsScript::onStart() {
}

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

void CheatsScript::onDestroy() {

}

void CheatsScript::onExternalEvent() {}