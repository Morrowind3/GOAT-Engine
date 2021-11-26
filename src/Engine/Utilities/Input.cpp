#include "Input.hpp"
#include <algorithm>
#include <SDL.h>

#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

using namespace Engine;

using KeyCode = Engine::Input::KeyCode;
using MouseButton = Engine::Input::MouseButton;

SDL_Event event; // Put here to ensure Pimpl

void Input::Update() {
    // Update last frame state
    _keysPressedLastFrame = {_keysPressedThisFrame};
    _mousePressedLastFrame = {_mousePressedThisFrame};

    // Get current frame state
    _keysPressedThisFrame = {}; _mousePressedThisFrame = {};
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) _keysPressedThisFrame[static_cast<KeyCode>(event.key.keysym.sym)] = true;
        if (event.type == SDL_KEYUP) _keysPressedThisFrame[static_cast<KeyCode>(event.key.keysym.sym)] = false;
        if (event.type == SDL_MOUSEBUTTONDOWN) _mousePressedThisFrame[static_cast<MouseButton>(event.button.button)] = true;
        if (event.type == SDL_MOUSEBUTTONUP) _mousePressedThisFrame[static_cast<MouseButton>(event.button.button)] = false;
    }
    SDL_GetMouseState(&_mousePositionX, &_mousePositionY);

    // Calculate ups and downs
    _keysUp = {}; // Keys up: key must be pressed last frame and released this frame
    for (auto& lastKeyPress : _keysPressedLastFrame) {
        if (!lastKeyPress.second) continue;
        auto currentFramePress = _keysPressedThisFrame.find(lastKeyPress.first);
        if (currentFramePress != _keysPressedThisFrame.end() && !currentFramePress->second)
            _keysUp.emplace_back(lastKeyPress.first);
    }

    _keysDown = {}; // Keys down: key must be pressed this frame but not exist last frame
    for (auto& currentKeyPress : _keysPressedThisFrame) {
        if (!currentKeyPress.second) continue;
        if (_keysPressedLastFrame.find(currentKeyPress.first) == _keysPressedLastFrame.end())
            _keysDown.emplace_back(currentKeyPress.first);
    }

    // And same with the mouse buttons
    _mouseUp = {};
    for (auto& lastMousePress : _mousePressedLastFrame) {
        if (!lastMousePress.second) continue;
        auto currentFramePress = _mousePressedLastFrame.find(lastMousePress.first);
        if (currentFramePress != _mousePressedLastFrame.end() && !currentFramePress->second)
            _mouseUp.emplace_back(lastMousePress.first);
    }

    _mouseDown = {};
    for (auto& currentMousePress : _mousePressedThisFrame) {
        if (!currentMousePress.second) continue;
        if (_mousePressedThisFrame.find(currentMousePress.first) == _mousePressedThisFrame.end())
            _mouseDown.emplace_back(currentMousePress.first);
    }
}

bool Input::AnyKey() const {
    for (auto& key: _keysPressedThisFrame) {
        if (key.second) return true;
    }
    return false;
}

bool Input::AnyKeyUp() const {
    return !_keysUp.empty();
}

bool Input::AnyKeyDown() const {
    return !_keysDown.empty();
}

bool Input::GetKey(KeyCode code) const {
    auto keyFind = _keysPressedThisFrame.find(code);
    return keyFind != _keysPressedThisFrame.end() && keyFind->second;
}

bool Input::GetKeyUp(KeyCode code) const {
    return std::find(_keysUp.begin(), _keysUp.end(), code) != _keysUp.end();
}

bool Input::GetKeyDown(KeyCode code) const {
    return std::find(_keysDown.begin(), _keysDown.end(), code) != _keysDown.end();
}

Point Input::MousePosition() const {
    return {_mousePositionX, _mousePositionY};
}

bool Input::AnyMouse() const {
    for (auto& key: _mousePressedThisFrame) {
        if (key.second) return true;
    }
    return false;
}

bool Input::AnyMouseUp() const {
    return !_mouseUp.empty();
}

bool Input::AnyMouseDown() const {
    return !_mouseDown.empty();
}

bool Input::GetMouseButton(MouseButton button) const {
    auto keyFind = _mousePressedThisFrame.find(button);
    return keyFind != _mousePressedThisFrame.end() && keyFind->second;
}

bool Input::GetMouseUp(MouseButton button) const {
    return std::find(_mouseUp.begin(), _mouseUp.end(), button) != _mouseUp.end();
}

bool Input::GetMouseDown(MouseButton button) const {
    return std::find(_mouseDown.begin(), _mouseDown.end(), button) != _mouseDown.end();
}

bool Input::QuitEvent() const {
    return event.type == SDL_QUIT || _manualQuitEvent;
}

void Input::QueueQuitEvent() {
    _manualQuitEvent = true;
}
