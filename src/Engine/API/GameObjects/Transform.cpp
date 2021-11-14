#include "Transform.hpp"

using namespace Engine;

Transform::Transform(Point position, double rotation, double scaleWidth, double scaleheight, FLIP flip)
        : position(position), _rotation(rotation), _scaleWidth(scaleWidth), _scaleheight(scaleheight), _flip(flip) {}