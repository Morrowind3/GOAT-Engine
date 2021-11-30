#ifndef GOAT_ENGINE_ENGINECALLS_HPP
#define GOAT_ENGINE_ENGINECALLS_HPP

/// Essentially system calls for the engine
namespace Engine {
    class GoatEngine; // Friend class
    class EngineCalls {
        friend class Engine::GoatEngine;
        public:
            EngineCalls(EngineCalls const&) = delete;
            void operator=(EngineCalls const&) = delete;
            static EngineCalls& getInstance() {
                static EngineCalls instance{};
                return instance;
            }

            [[nodiscard]] bool quitEventQueued() const;
            void queueQuitEvent();
            [[nodiscard]] bool isPaused() const;
            void pause(bool shouldBePaused);
            [[nodiscard]] double speed() const;
            void modifySpeed(double speed);
        private:
            EngineCalls() = default;
            bool _paused {false}, _quit {false};
            double _speed {1.0};
    };
}

#endif //GOAT_ENGINE_ENGINECALLS_HPP
