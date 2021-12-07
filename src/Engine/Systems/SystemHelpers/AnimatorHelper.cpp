#include "AnimatorHelper.hpp"

using namespace Engine;

void AnimatorHelper::resetForNextScene() {
    _animatorTracking.clear();
}

void AnimatorHelper::handleAnimator(Animator& animator, double deltaTime) {
    auto animatorTracker = _animatorTracking.find(&animator);
    if (animatorTracker == _animatorTracking.end()) {
        _animatorTracking.insert(std::make_pair(&animator,0));
    } else {
        animatorTracker->second += deltaTime;
        double deltaTimeTrigger = 1000.0/animator.fps;
        while (animatorTracker->second >= deltaTimeTrigger) {
            animatorTracker->second -= deltaTimeTrigger;
            animate(animator);
        }
    }
}

void AnimatorHelper::animate(Animator& animator) {
    if (animator.sprites.empty()) return; // Only works if animator isn't empty
    // Find current active sprite and make it inactive: the next sprite should become active!
    unsigned int activeSpritePosition = -1;
    for (int i = 0; i < animator.sprites.size(); ++i) {
        if (animator.sprites[i]->active) {
            animator.sprites[i]->active = false;
            activeSpritePosition = i;
            break;
        }
    }
    if (++activeSpritePosition >= animator.sprites.size()) {
        // When looping go to the first frame, when not looping stay at the last frame
        activeSpritePosition = animator.loop ? 0 : animator.sprites.size() - 1;
    }
    // Only next active sprite should be active
    for (auto& sprite: animator.sprites) {
        sprite->active = false;
    }
    animator.sprites[activeSpritePosition]->active = true;
}
