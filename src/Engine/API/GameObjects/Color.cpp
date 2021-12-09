#include "Color.hpp"

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a): R{r}, G{g}, B{b}, A{a} {
}

Color::Color(): Color(0,0,0,0) {
}

bool Color::operator==(const Color& other) const {
    return R == other.R && G == other.G && B == other.B && A == other.A;
}

bool Color::operator!=(const Color& other) const {
    return !(*this == other);
}

bool Color::operator<(const Color& other) const {
    return R < other.R && G < other.G && B < other.B && A < other.A;
}

bool Color::operator>(const Color& other) const {
    return R > other.R && G > other.G && B > other.B && A > other.A;
}

bool Color::operator<=(const Color& other) const {
    return (*this == other || *this < other);
}

bool Color::operator>=(const Color& other) const {
    return (*this == other || *this > other);
}
