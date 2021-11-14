#include "Transform.hpp"

using namespace Engine;

Transform::Transform(Point position, double rotation, double scaleWidth, double scaleHeight, FLIP flip)
        : position(position), rotation(rotation), scaleWidth(scaleWidth), scaleHeight(scaleHeight), flip(flip) {}