#ifndef GOAT_ENGINE_POINT_HPP
#define GOAT_ENGINE_POINT_HPP

struct Point {
    Point(double x, double y); // Primary constructor
    Point(int x, int y); // Easy int to double cast constructor
    Point(); // Empty point constructor
    double x, y;
};

#endif //GOAT_ENGINE_POINT_HPP
