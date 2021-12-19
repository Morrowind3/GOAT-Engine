#ifndef GOAT_ENGINE_LAYERGROUP_HPP
#define GOAT_ENGINE_LAYERGROUP_HPP

/// Layer group
namespace Engine {
    struct LayerGroup {
        explicit LayerGroup(bool ui = false, double parallax = 1.0);
        // When UI bool is true, this layer group is "static" and gets drawn on screen instead of scene coordinates
        bool ui;
        // Determines how many pixels this layer should move as a multiplication, based on camera movement pixels
        // So a parallax of 0 doesn't move at all, 1 moves 1 pixel ("normal") and anything above that moves more than 1
        double parallax;
    };
}

#endif //GOAT_ENGINE_LAYERGROUP_HPP
