#include "Point.hpp"

Point::Point(double x, double y) : x(x), y(y) {}
Point::Point(int x, int y): Point((double)x,(double)y) {}
