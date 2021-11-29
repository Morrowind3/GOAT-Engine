#include "Input.hpp"
#include <algorithm>
#include <SDL.h>

using namespace Engine;

void Input::update() {
    _registry.flushForNextFrame();
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) { _engineCalls.queueQuitEvent(); return; }
        if (event.type == SDL_KEYDOWN) _registry.storeKeyDown(static_cast<KeyCode>(event.key.keysym.sym));
        if (event.type == SDL_KEYUP) _registry.storeKeyUp(static_cast<KeyCode>(event.key.keysym.sym));
        if (event.type == SDL_MOUSEBUTTONDOWN) _registry.storeMouseDown(static_cast<MouseButton>(event.button.button));
        if (event.type == SDL_MOUSEBUTTONUP) _registry.storeMouseUp(static_cast<MouseButton>(event.button.button));
    }
    SDL_GetMouseState(&_mousePositionX, &_mousePositionY);
}

bool Input::anyKey() const {
    return _registry.anyKeyRegistered();
}

bool Input::anyKeyUp() const {
    return _registry.anyKeyInState(PressState::RELEASED);
}

bool Input::anyKeyDown() const {
    return _registry.anyKeyInState(PressState::PRESSED);
}

bool Input::getKey(KeyCode code) const {
    return _registry.keyStatus(code) != PressState::UNDETECTED;
}

bool Input::getKeyUp(KeyCode code) const {
    return _registry.keyStatus(code) == PressState::RELEASED;
}

bool Input::getKeyDown(KeyCode code) const {
    return _registry.keyStatus(code) == PressState::PRESSED;
}

Point Input::mousePosition() const {
    return {_mousePositionX, _mousePositionY};
}

bool Input::anyMouse() const {
    return _registry.anyMouseRegistered();
}

bool Input::anyMouseUp() const {
    return _registry.anyMouseInState(PressState::RELEASED);
}

bool Input::anyMouseDown() const {
    return _registry.anyMouseInState(PressState::PRESSED);
}

bool Input::getMouse(MouseButton button) const {
    return _registry.mouseStatus(button) != PressState::UNDETECTED;
}

bool Input::getMouseUp(MouseButton button) const {
    return _registry.mouseStatus(button) == PressState::RELEASED;
}

bool Input::getMouseDown(MouseButton button) const {
    return _registry.mouseStatus(button) == PressState::PRESSED;
}
