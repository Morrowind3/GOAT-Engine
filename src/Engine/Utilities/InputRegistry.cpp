#include "InputRegistry.hpp"
#include <algorithm>

using namespace Engine;

// All keys that were pressed last frame are now in a held state
// All keys that were released last frame are removed (implicit undetected state)
void InputRegistry::FlushForNextFrame() {
    for (auto& key : _keyStates) {
        if (key.second == PressState::PRESSED) key.second = PressState::HELD;
        if (key.second == PressState::RELEASED) _keyStates.erase(key.first);
    }
    for (auto& button : _mouseStates) {
        if (button.second == PressState::PRESSED) button.second = PressState::HELD;
        if (button.second == PressState::RELEASED) _mouseStates.erase(button.first);
    }
}

void InputRegistry::StoreKeyDown(KeyCode key) {
    // Key down event gets sent multiple times when key is held, which is useful in a text editor but not in a game
    if (KeyStatus(key) != PressState::HELD) _keyStates[key] = PressState::PRESSED;
}

void InputRegistry::StoreKeyUp(KeyCode key) {
    _keyStates[key] = PressState::RELEASED;
}

bool InputRegistry::AnyKeyRegistered() const {
    return !_keyStates.empty();
}

bool InputRegistry::AnyKeyInState(PressState state) const {
    return std::find_if(_keyStates.begin(),_keyStates.end(),
                        [state](const auto& key){return key.second == state;}) != _keyStates.end();
}

PressState InputRegistry::KeyStatus(KeyCode key) const {
    auto keyIterator = _keyStates.find(key);
    return keyIterator != _keyStates.end() ? keyIterator->second : PressState::UNDETECTED;
}

void InputRegistry::StoreMouseDown(MouseButton button) {
    _mouseStates[button] = PressState::PRESSED;
}

void InputRegistry::StoreMouseUp(MouseButton button) {
    _mouseStates[button] = PressState::RELEASED;
}

bool InputRegistry::AnyMouseRegistered() const {
    return !_mouseStates.empty();
}

bool InputRegistry::AnyMouseInState(PressState state) const {
    return std::find_if(_mouseStates.begin(),_mouseStates.end(),
                        [state](const auto& button){return button.second == state;}) != _mouseStates.end();
}

PressState InputRegistry::MouseStatus(MouseButton button) const {
    auto mouseIterator = _mouseStates.find(button);
    return mouseIterator != _mouseStates.end() ? mouseIterator->second : PressState::UNDETECTED;
}


