#ifndef GOAT_ENGINE_DEBUG_HPP
#define GOAT_ENGINE_DEBUG_HPP

#include <string>

namespace Engine {
    class Debug {
        public:
            Debug(Debug const&) = delete;
            void operator=(Debug const&) = delete;
            static Debug& getInstance() {
                static Debug instance;
                return instance;
            }
            void log(const std::string& message) const;
            void toggle(bool active);
            [[nodiscard]] bool isActive() const;
        private:
            Debug()= default;
            bool _active;
    };
}

#endif //GOAT_ENGINE_DEBUG_HPP
