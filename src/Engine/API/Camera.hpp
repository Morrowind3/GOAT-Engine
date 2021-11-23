//
// Created by Morrowind3 on 23/11/2021.
//

#ifndef GOAT_ENGINE_CAMERA_HPP
#define GOAT_ENGINE_CAMERA_HPP


#include <SDL_rect.h>
#include <vector>
#include "GameObjects/GameObject.hpp"
#include "GameObjects/Rectangle.hpp"

class Camera {
public:
    Camera(double x, double y, double width, double height): camera({Point{x,y}, width, height}){};
    Engine::Transform AdjustForCamera(const Engine::Transform& transform);
    void MoveCamera(double x, double y);
private:
    void Reposition(Engine::Transform& t) const;
    void Crop(Engine::Transform& t) const;
    void Zoom(Engine::Transform& t) const;

    Rectangle camera;
};


#endif //GOAT_ENGINE_CAMERA_HPP
