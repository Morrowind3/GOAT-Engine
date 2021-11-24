#include "Input.hpp"
#include <SDL.h>
#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

using namespace Engine;

using KeyCode = Engine::Input::KeyCode;
using MouseButton = Engine::Input::MouseButton;

SDL_Event event;

void Input::Update() {
    SDL_PumpEvents();
    SDL_PollEvent(&event);
}

bool Input::AnyKeyDown() const {
    return (event.type == SDL_KEYDOWN);
}

bool Input::GetKeyDown(KeyCode code) const {
    return (event.type == SDL_KEYDOWN && event.key.keysym.sym == static_cast<SDL_KeyCode>(code) );
}

Point Input::MousePosition() const {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return Point(x, y);
}

bool Input::AnyMouse() const {
    return SDL_GetMouseState(nullptr, NULL);
}

bool Input::AnyMouseUp() const {
    return (event.type == SDL_MOUSEBUTTONUP);
}

bool Input::AnyMouseDown() const {
    return (event.type == SDL_MOUSEBUTTONDOWN);
}

bool Input::GetMouseButton(MouseButton button) const {
    return (static_cast<MouseButton>(event.button.button) == button);
}

bool Input::GetMouseUp(MouseButton button) const {
    return (event.type == SDL_MOUSEBUTTONUP && static_cast<MouseButton>(event.button.button) == button);
}

bool Input::GetMouseDown(MouseButton button) const {
    return (event.type == SDL_MOUSEBUTTONDOWN && static_cast<MouseButton>(event.button.button) == button);
}

bool Input::QuitEvent() const {
    return event.type == SDL_QUIT || _manualQuitEvent;
}

void Input::QueueQuitEvent() {
    _manualQuitEvent = true;
}


#pragma clang diagnostic pop
#pragma clang diagnostic pop