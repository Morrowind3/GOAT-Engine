#include "Script_TrashCounter.hpp"
#include "../../../Keys.hpp"

Script_TrashCounter::Script_TrashCounter(Text& trashText, bool active) : Script(active), _text(trashText){}

void Script_TrashCounter::onUpdate(double deltaTime) {
    if(_globals.gameExists(Keys::TRASH_MAX)){
        std::string total = _globals.gameGet(Keys::TRASH_MAX);
        if(_total != total){
            _total = total;
            if(total.length() < 2) total.insert(0, "0");
            _text.text.insert(2, "/"+total);
        }
    }

    // Only update the text when the amount of trash has actually changed
    if(!_globals.gameExists(Keys::TRASH)) return;
    auto gameTrash = _globals.gameGet(Keys::TRASH);
    if (gameTrash == _currentTrash) return;
    _currentTrash = gameTrash;

    if(_currentTrash.length() > 1){
        _text.text.at(0) = _currentTrash.at(0);
        _text.text.at(1) = _currentTrash.at(1);
    } else {
        _text.text.at(0) = '0';
        _text.text.at(1) = _currentTrash.at(0);
    }
}
