#include "Script_TrashCounter.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../Keys.hpp"

void Script_TrashCounter::onUpdate(double deltaTime) {
    if(Globals::getInstance().gameExists(Keys::TRASH_MAX)){
        std::string total = Globals::getInstance().gameGet(Keys::TRASH_MAX);
        if(_total != total){
            _total = total;
            if(total.length() < 2) total.insert(0, "0");
            _text.text.insert(2, "/"+total);
        }
    }

    if(!Globals::getInstance().sceneExists(Keys::TRASH) || Globals::getInstance().sceneGet(Keys::TRASH) == _currentTrash) return;
    _currentTrash = Globals::getInstance().sceneGet(Keys::TRASH);
    if(_currentTrash.length() > 1){
        _text.text.at(0) = _currentTrash.at(0);
        _text.text.at(1) = _currentTrash.at(1);
    } else {
        _text.text.at(0) = '0';
        _text.text.at(1) = _currentTrash.at(0);
    }
}
