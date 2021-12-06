#include "Transform.hpp"

using namespace Engine;

Transform::Transform(Point position, unsigned int layerGroup, double rotation, double scaleWidth, double scaleHeight, FLIP flip, unsigned int layer)
        : position{position}, layerGroup{layerGroup}, rotation{rotation}, scaleWidth{scaleWidth}, scaleHeight{scaleHeight}, flip{flip}, layer{layer} {}