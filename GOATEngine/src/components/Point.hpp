#ifndef GOATENGINE_POINT_HPP
#define GOATENGINE_POINT_HPP

namespace Engine {
    class Point {
        public:
            explicit Point(float x, float y);
            [[nodiscard]] float x() const;
            [[nodiscard]] float y() const;
            void x(float x);
            void y(float y);
        private:
            float _x, _y;
    };
}

#endif //GOATENGINE_POINT_HPP
