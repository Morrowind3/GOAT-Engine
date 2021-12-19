#ifndef GOAT_ENGINE_CLOCK_HPP
#define GOAT_ENGINE_CLOCK_HPP

#include "EngineCalls.hpp"

/// Engine's clock to PIMPL out SDL
namespace Engine {
    class GoatEngine; // Friend class link
    class Clock {
        friend class Engine::GoatEngine;
        public:
            Clock(Clock const&) = delete;
            void operator=(Clock const&) = delete;
            static Clock& getInstance() {
                static Clock instance;
                return instance;
            }
            [[nodiscard]] double getMaxFps() const;
            [[nodiscard]] double lastRecordedUnmodifiedDeltaTime() const;
        private:
            Clock(){};
            void setMaxFps(unsigned int maxFps);
            bool tickAndCheckIfNextFrameIsReady();
            [[maybe_unused]] [[nodiscard]] double actualDeltaTime() const;
            [[nodiscard]] double gameStateBasedDeltaTime() const;
            [[nodiscard]] static unsigned int getTicks();

            EngineCalls& _engineCalls = EngineCalls::getInstance();
            unsigned int _currentFrameTickInMs{0}, _previousFrameTickInMs = getTicks();
            double _lastRecordedUnmodifiedDeltaTimeInMs{0}, _deltaTimeInMs {0}, _frameDelayInMs {1000.0/60.0}; // Default value for 60FPS
    };
}


#endif //GOAT_ENGINE_CLOCK_HPP
