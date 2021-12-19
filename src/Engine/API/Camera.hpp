#ifndef GOAT_ENGINE_CAMERA_HPP
#define GOAT_ENGINE_CAMERA_HPP

#include <queue>
#include <functional>
#include "GameObjects/GameObject.hpp"
#include "GameObjects/Rectangle.hpp"
#include "LayerGroup.hpp"

namespace Engine {
    class Camera {
        public:
            Camera(Rectangle& sceneViewPort, std::map<unsigned int,LayerGroup>& layerGroups, float zoom);

            Transform adjustForCamera(const Transform& logicalPosition);
            void trackObject(std::shared_ptr<GameObject> object);
            [[maybe_unused]] void moveCamera(double x, double y);
            [[maybe_unused]] void setZoomLevel(float zoom);
            [[maybe_unused]] void addWaypoint(Point waypoint, int seconds);
            [[maybe_unused]] void addWaypoint(Point waypoint, int seconds, float zoomLevel);
            [[maybe_unused]] void interpolateToNextWaypoint();

        private:
            struct WaypointParams {
                double xPerMs;
                double yPerMs;
                float zoomPerMs;
                Point destination;
                float zoomTarget;
            };
            // Methods
            void trackObject();
            void reposition(Transform& transform) const;
            void zoom(Transform& t) const;
            // Variables
            std::shared_ptr<GameObject> _trackedObject = nullptr;
            std::queue<WaypointParams> _waypoints;
            std::map<unsigned int,LayerGroup>& _layerGroups;
            Rectangle& _sceneViewPort;
            float _zoomLevel;
    };
};


#endif //GOAT_ENGINE_CAMERA_HPP