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
    //width and height unused until we need to crop.
    Camera(double x, double y, float zoom): camera({Point{x,y}, 0, 0}), zoomLevel(zoom){};
    Engine::Transform AdjustForCamera(const Engine::Transform& transform);
    void MoveCamera(double x, double y);
    void setZoomLevel(float zoom);
private:
    void Reposition(Engine::Transform& t) const;
    void Zoom(Engine::Transform& t) const;
    Rectangle camera;
    float zoomLevel;
};


#endif //GOAT_ENGINE_CAMERA_HPP
