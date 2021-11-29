#ifndef GOAT_ENGINE_CLOCK_HPP
#define GOAT_ENGINE_CLOCK_HPP

#include "EngineCalls.hpp"

/// Engine's clock to PIMPL out SDL
namespace Engine {
    class GoatEngine; // Friend class link
    class Clock {
        friend class Engine::GoatEngine;
        public:
            Clock() = delete;
        private:
            explicit Clock(unsigned int maxFps);
            bool tickAndCheckIfNextFrameIsReady();
            [[maybe_unused]] [[nodiscard]] double actualDeltaTime() const;
            [[nodiscard]] double gameStateBasedDeltaTime() const;
            [[nodiscard]] static unsigned int getTicks();

            EngineCalls& _engineCalls = EngineCalls::getInstance();
            const double _frameDelayInMs;
            unsigned int _currentFrameTickInMs, _previousFrameTickInMs = getTicks();
            double _deltaTimeInMs {0};
    };
}


#endif //GOAT_ENGINE_CLOCK_HPP
