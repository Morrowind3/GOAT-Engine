#include "Transform.hpp"

using namespace Engine;

Transform::Transform(Point position, unsigned int layer, double rotation, double scaleWidth, double scaleHeight, FLIP flip)
        : position{position}, layer{layer}, rotation{rotation}, scaleWidth{scaleWidth}, scaleHeight{scaleHeight}, flip{flip} {}