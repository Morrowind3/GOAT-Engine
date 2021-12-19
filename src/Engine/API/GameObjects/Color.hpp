#ifndef GOAT_ENGINE_COLOR_HPP
#define GOAT_ENGINE_COLOR_HPP

#include <string>

struct Color {
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    Color(); // For "invisible" colors
    uint8_t R,G,B,A;
    bool operator==(const Color &other) const;
    bool operator!=(const Color &other) const;
    // These are pretty arbitrary but all operators are required for tuples
    bool operator<(const Color &other) const;
    bool operator>(const Color &other) const;
    bool operator<=(const Color &other) const;
    bool operator>=(const Color &other) const;
};

#endif //GOAT_ENGINE_COLOR_HPP
