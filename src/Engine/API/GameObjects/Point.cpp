#include "Point.hpp"

using namespace Engine;

Point::Point(double x, double y) : x(x), y(y) {}
Point::Point(int x, int y): Point((double)x,(double)y) {}
Point::Point(): Point(0.0,0.0) {}
