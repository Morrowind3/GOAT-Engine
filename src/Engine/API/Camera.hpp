#ifndef GOAT_ENGINE_CAMERA_HPP
#define GOAT_ENGINE_CAMERA_HPP

#include <SDL_rect.h>
#include <queue>
#include <functional>
#include "GameObjects/GameObject.hpp"
#include "GameObjects/Rectangle.hpp"


namespace Engine{
    class Camera {
        public:
            Camera(): _camera({Point{0, 0}, 0, 0}), _zoomLevel(1){};
            //width and height unused until we need to crop.
            Camera(double x, double y, float zoom): _camera({Point{x, y}, 0, 0}), _zoomLevel(zoom){};
            Engine::Transform AdjustForCamera(const Engine::Transform& transform);
            void MoveCamera(double x, double y);
            void InterpolateToNextWaypoint();
            void TrackObject(std::shared_ptr<GameObject> object);
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
        //        std::function<bool()> endCondition; TODO: Scriptable end condition.
            };
            void TrackObject();
            std::shared_ptr<GameObject> _trackedObject = nullptr;
            void Reposition(Engine::Transform& t) const;
            void Zoom(Engine::Transform& t) const;
            std::queue<WaypointParams> _waypoints;
            Engine::Rectangle _camera;
            float _zoomLevel;
    };
};


#endif //GOAT_ENGINE_CAMERA_HPP