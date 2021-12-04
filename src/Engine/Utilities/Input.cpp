#include "Input.hpp"
#include <algorithm>
#include <SDL.h>

using namespace Engine;

// Updates

void Input::update() {
    _registry.flushForNextFrame();
    registerEvents();
    handleMouseLocation();
}

void Input::registerEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) { _engineCalls.queueQuitEvent(); return; }
        if (event.type == SDL_KEYDOWN) _registry.storeKeyDown(static_cast<KeyCode>(event.key.keysym.sym));
        if (event.type == SDL_KEYUP) _registry.storeKeyUp(static_cast<KeyCode>(event.key.keysym.sym));
        if (event.type == SDL_MOUSEBUTTONDOWN) _registry.storeMouseDown(static_cast<MouseButton>(event.button.button));
        if (event.type == SDL_MOUSEBUTTONUP) _registry.storeMouseUp(static_cast<MouseButton>(event.button.button));
    }
}

void Input::handleMouseLocation() {
    SDL_GetMouseState(&_mousePositionX, &_mousePositionY); // This is based on window size and needs translation
    // Adjust for state of the screen so that the actual mouse position translates to a logical mouse position
    const Point viewPortSize = _engineCalls.viewPortSize();
    const Point windowSize = _engineCalls.windowSize();
    const double xAspectRatio = viewPortSize.x/windowSize.x;
    const double yAspectRatio = viewPortSize.y/windowSize.y;
    Point aspectRatioCorrections {0,0}; // TODO: Find the magical calculation that calculates this properly
    // Correct for aspect ratio
    _mousePositionX = (_mousePositionX * xAspectRatio) + aspectRatioCorrections.x;
    _mousePositionY = (_mousePositionY * yAspectRatio) + aspectRatioCorrections.y;
}

// Gets

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
