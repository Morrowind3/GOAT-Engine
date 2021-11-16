//
// Created by Morrowind3 on 14/11/2021.
//

#include "Input.hpp"
#include <SDL.h>
#include <cstdio>
#include <sstream>
#include <iostream>

using namespace Engine;
using KeyCode = Engine::Input::KeyCode;
using MouseButton = Engine::Input::MouseButton;


SDL_Event event;

//TODO: Kan dit niet gewoon in de constructor?
void Input::Init() {
}

void Input::Update() {
    SDL_PollEvent(&event);
    bool test = AnyMouse();
    if(test){
        std::cout << "Mouse: " << MousePosition().x << "," << MousePosition().y << std::endl;
    }
}

const bool Input::AnyKey() {
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    return keyState[static_cast<SDL_KeyCode>(event.key.keysym.sym)];
}

const bool Input::AnyKeyUp() {
    return (event.type == SDL_KEYUP);
}

const bool Input::AnyKeydown() {
    return (event.type == SDL_KEYDOWN);
}

const bool Input::GetKey(KeyCode code) {
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    return keyState[static_cast<SDL_KeyCode>(code)];
}

const bool Input::GetKeyUp(KeyCode code) {
    return (event.type == SDL_KEYUP && event.key.keysym.sym == static_cast<SDL_KeyCode>(code) );
}

const bool Input::GetKeyDown(KeyCode code) {
    return (event.type == SDL_KEYDOWN && event.key.keysym.sym == static_cast<SDL_KeyCode>(code) );
}

const Point Input::MousePosition() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return Point(x, y);
}

const bool Input::AnyMouse() {
    return SDL_GetMouseState(NULL, NULL);
}

const bool Input::AnyMouseUp() {
    return (event.type == SDL_MOUSEBUTTONUP);
}

const bool Input::AnyMouseDown() {
    return (event.type == SDL_MOUSEBUTTONDOWN);
}

const bool Input::GetMouseButton(MouseButton button) {
    return (static_cast<MouseButton>(event.button.button) == button);
}

const bool Input::GetMouseUp(MouseButton button) {
    return (event.type == SDL_MOUSEBUTTONUP && static_cast<MouseButton>(event.button.button) == button);

}

const bool Input::GetMouseDown(MouseButton button) {
    return (event.type == SDL_MOUSEBUTTONDOWN && static_cast<MouseButton>(event.button.button) == button);

}

