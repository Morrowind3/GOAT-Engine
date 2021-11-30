#include "Debug.hpp"
#include <iostream>

using namespace Engine;

void Debug::log(const std::string& message) const {
    if(_active) std::cout << message << '\n';
}

void Debug::toggle(bool active) {
    _active = active;
    if (_active) std::cout << "Debug messaging enabled" << '\n';
    else std::cout << "Debug messaging disabled" << '\n';
}

bool Debug::isActive() const {
    return _active;
}
