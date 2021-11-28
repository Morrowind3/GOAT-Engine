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
            Engine::Transform adjustForCamera(const Engine::Transform& transform);

            void moveCamera(double x, double y);
            void interpolateToNextWaypoint();
            void trackObject(std::shared_ptr<GameObject> object);
            void setZoomLevel(float zoom);
            void addWaypoint(Point waypoint, int seconds);
            void addWaypoint(Point waypoint, int seconds, float zoomLevel);

        private:
            struct WaypointParams {
                double xPerMs;
                double yPerMs;
                float zoomPerMs;
                Point destination;
                float zoomTarget;
        //        std::function<bool()> endCondition; TODO: Scriptable end condition.
            };

            void trackObject();
            void reposition(Engine::Transform& t) const;
            void zoom(Engine::Transform& t) const;

            std::shared_ptr<GameObject> _trackedObject = nullptr;
            std::queue<WaypointParams> _waypoints;
            Engine::Rectangle _camera;
            float _zoomLevel;
    };
};


#endif //GOAT_ENGINE_CAMERA_HPP