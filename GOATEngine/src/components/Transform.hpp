#ifndef GOATENGINE_TRANSFORM_HPP
#define GOATENGINE_TRANSFORM_HPP

#include "Point.hpp"

namespace Engine {
    class Transform {
        public:
            Transform(Point position, float rotation, float scaleX, float scaleY);
            [[nodiscard]] const Point& position() const;
            [[nodiscard]] float rotation() const;
            [[nodiscard]] float scaleX() const;
            [[nodiscard]] float scaleY() const;
            void position(Point position);
            void rotation(float rotation);
            void scaleX(float scaleX);
            void scaleY(float scaleY);
        private:
            Point _position;
            float _rotation, _scaleX, _scaleY;
    };
}

#endif //GOATENGINE_TRANSFORM_HPP
