#include "InputRegistry.hpp"
#include <algorithm>

using namespace Engine;

// All keys that were pressed last frame are now in a held state
// All keys that were released last frame are now in an undetected state
void InputRegistry::flushForNextFrame() {
    for (auto& key : _keyStates) {
        if (key.second == PressState::PRESSED) key.second = PressState::HELD;
        if (key.second == PressState::RELEASED) key.second = PressState::UNDETECTED;
    }
    for (auto& button : _mouseStates) {
        if (button.second == PressState::PRESSED) button.second = PressState::HELD;
        if (button.second == PressState::RELEASED) button.second = PressState::UNDETECTED;
    }
}

void InputRegistry::storeKeyDown(KeyCode key) {
    // Key down event gets sent multiple times when key is held, which is useful in a text editor but not in a game
    if (keyStatus(key) != PressState::HELD) _keyStates[key] = PressState::PRESSED;
}

void InputRegistry::storeKeyUp(KeyCode key) {
    _keyStates[key] = PressState::RELEASED;
}

bool InputRegistry::anyKeyRegistered() const {
    return std::find_if(_keyStates.begin(),_keyStates.end(),
                        [](const auto& key){return key.second != PressState::UNDETECTED;}) == _keyStates.end();
}

bool InputRegistry::anyKeyInState(PressState state) const {
    return std::find_if(_keyStates.begin(),_keyStates.end(),
                        [state](const auto& key){return key.second == state;}) != _keyStates.end();
}

PressState InputRegistry::keyStatus(KeyCode key) const {
    auto keyIterator = _keyStates.find(key);
    return keyIterator != _keyStates.end() ? keyIterator->second : PressState::UNDETECTED;
}

void InputRegistry::storeMouseDown(MouseButton button) {
    _mouseStates[button] = PressState::PRESSED;
}

void InputRegistry::storeMouseUp(MouseButton button) {
    _mouseStates[button] = PressState::RELEASED;
}

bool InputRegistry::anyMouseRegistered() const {
    return std::find_if(_mouseStates.begin(),_mouseStates.end(),
                        [](const auto& button){return button.second != PressState::UNDETECTED;}) == _mouseStates.end();
}

bool InputRegistry::anyMouseInState(PressState state) const {
    return std::find_if(_mouseStates.begin(),_mouseStates.end(),
                        [state](const auto& button){return button.second == state;}) != _mouseStates.end();
}

PressState InputRegistry::mouseStatus(MouseButton button) const {
    auto mouseIterator = _mouseStates.find(button);
    return mouseIterator != _mouseStates.end() ? mouseIterator->second : PressState::UNDETECTED;
}


