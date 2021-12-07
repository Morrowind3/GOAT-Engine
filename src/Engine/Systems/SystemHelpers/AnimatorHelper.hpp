#ifndef GOAT_ENGINE_ANIMATORHELPER_HPP
#define GOAT_ENGINE_ANIMATORHELPER_HPP

#include <map>
#include "../../API/GameObjects/GameComponents/Render/Animator.hpp"

namespace Engine {
    class AnimatorHelper {
        public:
            void resetForNextScene();
            void handleAnimator(Animator& animator, double deltaTime);
        private:
            std::map<Animator*,double> _animatorTracking {};
            static void animate(Animator& animator);
    };
}

#endif //GOAT_ENGINE_ANIMATORHELPER_HPP
