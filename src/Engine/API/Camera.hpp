#ifndef GOAT_ENGINE_CAMERA_HPP
#define GOAT_ENGINE_CAMERA_HPP

#include <SDL_rect.h>
#include <queue>
#include <functional>
#include "GameObjects/GameObject.hpp"
#include "GameObjects/Rectangle.hpp"

//<Coordinates, seconds, zoom>
class Camera {
public:
    Camera(): camera({Point{0,0},0,0}), zoomLevel(1){};
    //width and height unused until we need to crop.
    Camera(double x, double y, float zoom): camera({Point{x,y}, 0, 0}), zoomLevel(zoom){};
    Engine::Transform AdjustForCamera(const Engine::Transform& transform);
    void MoveCamera(double x, double y);
    void InterpolateToNextWaypoint();
    void SetZoomLevel(float zoom);
    void AddWaypoint(Point waypoint, int seconds);
    void AddWaypoint(Point waypoint, int seconds, float zoomLevel);
private:
    struct WaypointParams {
        double xPerMs;
        double yPerMs;
        float zoomPerMs;
        Point destination;
        float zoomTarget;
        std::function<bool()> endCondition;
                int ticks;

    };

    void Reposition(Engine::Transform& t) const;
    void Zoom(Engine::Transform& t) const;
    std::queue<WaypointParams> waypoints;
    Engine::Rectangle camera;
    float zoomLevel;
};


#endif //GOAT_ENGINE_CAMERA_HPP