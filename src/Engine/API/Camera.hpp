#ifndef GOAT_ENGINE_CAMERA_HPP
#define GOAT_ENGINE_CAMERA_HPP

#include <queue>
#include <functional>
#include "GameObjects/GameObject.hpp"
#include "GameObjects/Rectangle.hpp"

namespace Engine{
    class Camera {
        public:
            Camera(Rectangle& sceneViewPort, Point& sceneDimensions, float zoom);
            Transform adjustForCamera(const Engine::Transform& transform);

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
            Rectangle& _sceneViewPort;
            Point& _sceneDimensions;
            float _zoomLevel;
    };
};


#endif //GOAT_ENGINE_CAMERA_HPP