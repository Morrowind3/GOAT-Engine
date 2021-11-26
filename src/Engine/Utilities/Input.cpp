#include "Input.hpp"
#include <algorithm>
#include <SDL.h>

using namespace Engine;

void Input::Update() {
    _registry.FlushForNextFrame();
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) { QueueQuitEvent(); return; }
        if (event.type == SDL_KEYDOWN) _registry.StoreKeyDown(static_cast<KeyCode>(event.key.keysym.sym));
        if (event.type == SDL_KEYUP) _registry.StoreKeyUp(static_cast<KeyCode>(event.key.keysym.sym));
        if (event.type == SDL_MOUSEBUTTONDOWN) _registry.StoreMouseDown(static_cast<MouseButton>(event.button.button));
        if (event.type == SDL_MOUSEBUTTONUP) _registry.StoreMouseUp(static_cast<MouseButton>(event.button.button));
    }
    SDL_GetMouseState(&_mousePositionX, &_mousePositionY);
}

bool Input::AnyKey() const {
    return _registry.AnyKeyRegistered();
}

bool Input::AnyKeyUp() const {
    return _registry.AnyKeyInState(PressState::RELEASED);
}

bool Input::AnyKeyDown() const {
    return _registry.AnyKeyInState(PressState::PRESSED);
}

bool Input::GetKey(KeyCode code) const {
    return _registry.KeyStatus(code) != PressState::UNDETECTED;
}

bool Input::GetKeyUp(KeyCode code) const {
    return _registry.KeyStatus(code) == PressState::RELEASED;
}

bool Input::GetKeyDown(KeyCode code) const {
    return _registry.KeyStatus(code) == PressState::PRESSED;
}

Point Input::MousePosition() const {
    return {_mousePositionX, _mousePositionY};
}

bool Input::AnyMouse() const {
    return _registry.AnyMouseRegistered();
}

bool Input::AnyMouseUp() const {
    return _registry.AnyMouseInState(PressState::RELEASED);
}

bool Input::AnyMouseDown() const {
    return _registry.AnyMouseInState(PressState::PRESSED);
}

bool Input::GetMouse(MouseButton button) const {
    return _registry.MouseStatus(button) != PressState::UNDETECTED;
}

bool Input::GetMouseUp(MouseButton button) const {
    return _registry.MouseStatus(button) == PressState::RELEASED;
}

bool Input::GetMouseDown(MouseButton button) const {
    return _registry.MouseStatus(button) == PressState::PRESSED;
}

bool Input::QuitEvent() const {
    return _quitEvent;
}

void Input::QueueQuitEvent() {
    _quitEvent = true;
}
