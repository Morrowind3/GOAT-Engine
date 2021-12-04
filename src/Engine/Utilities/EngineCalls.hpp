#ifndef GOAT_ENGINE_ENGINECALLS_HPP
#define GOAT_ENGINE_ENGINECALLS_HPP

#include "../API/GameObjects/Point.hpp"

/// Essentially system calls for the engine
namespace Engine {
    // Friend class links
    class GoatEngine;
    class RendererImpl;
    class EngineCalls {
        friend class Engine::GoatEngine;
        friend class Engine::RendererImpl;
        public:
            EngineCalls(EngineCalls const&) = delete;
            void operator=(EngineCalls const&) = delete;
            static EngineCalls& getInstance() {
                static EngineCalls instance{};
                return instance;
            }
            // Quit engine
            [[nodiscard]] bool quitEventQueued() const;
            void queueQuitEvent();
            // Pause engine
            [[nodiscard]] bool isPaused() const;
            void pause(bool shouldBePaused);
            // Engine speed
            [[nodiscard]] double speed() const;
            void modifySpeed(double speed);
            // Screen sizes
            [[nodiscard]] Point viewPortSize() const;
            [[nodiscard]] Point windowSize() const;
            // TODO: Scene manager change scene
        private:
            // Singleton
            EngineCalls() = default;
            // Friend class methods for methods that are too destructive for the game programmer
            void viewPortSize(Point viewPortSize);
            void windowSize(Point windowSize);
            // State
            bool _paused {false}, _quit {false};
            double _speed {1.0};
            Point _viewPortSize, _windowSize;
    };
}

#endif //GOAT_ENGINE_ENGINECALLS_HPP
