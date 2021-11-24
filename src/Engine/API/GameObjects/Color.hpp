#ifndef GOAT_ENGINE_COLOR_HPP
#define GOAT_ENGINE_COLOR_HPP

#include <string>

struct Color {
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    uint8_t R,G,B,A;
    bool operator==(const Color &other) const {
        return R == other.R && G == other.G && B == other.B && A == other.A;
    }
    bool operator!=(const Color &other) const {
        return !(*this == other);
    }

    //these are pretty arbitrary but all operators are required for tuples.
    bool operator<(const Color &other) const {
        return R < other.R && G < other.G && B < other.B && A < other.A;
    }
    bool operator>(const Color &other) const {
        return R > other.R && G > other.G && B > other.B && A > other.A;
    }
    bool operator<=(const Color &other) const {
        return (*this == other || *this < other);
    }
    bool operator>=(const Color &other) const {
        return (*this == other || *this > other);
    }
};

#endif //GOAT_ENGINE_COLOR_HPP
