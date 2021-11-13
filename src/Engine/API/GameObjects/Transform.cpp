#include "Transform.hpp"

Transform::Transform(Point position, double rotation, double width, double height)
    : position(position), rotation(rotation), width(width), height(height)
{
}

Transform::Transform(Point position) : Transform(position, 0.0, 1.0,1.0)
{
}