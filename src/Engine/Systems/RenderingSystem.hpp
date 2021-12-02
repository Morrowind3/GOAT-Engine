#pragma once

#include "System.hpp"
#include "../Systems/Apis/RendererApi.hpp"

namespace Engine {
    class RenderingSystem : public System {
        public:
            RenderingSystem(std::string& name, std::string& iconPath, std::string& cursor);
            void onLaunchEngine() override;
            void onLoadScene(std::shared_ptr<Scene> scene) override;
            void onFrameTick(double deltaTime) override;
            void onCloseEngine() override;
        private:
            // Helper methods
            void handleAnimators(GameObject& gameObject, double deltaTime);
            void drawSprites(GameObject& gameObject);
            void drawText(GameObject& gameObject);
            void drawButtons(GameObject& gameObject);
            // Variables
            RendererApi* _api = nullptr;
            std::string& _name, _iconPath, _cursor;
            // Animator helper TODO: Find a better position for this
            class AnimatorHelper {
                public:
                    void resetForNextScene() {
                        _animatorTracking.clear();
                    }
                    void handleAnimator(Animator& animator, double deltaTime) {
                        auto animatorTracker = _animatorTracking.find(&animator);
                        if (animatorTracker == _animatorTracking.end()) {
                            _animatorTracking.insert(std::make_pair(&animator,0));
                        } else {
                            animatorTracker->second += deltaTime;
                            if (1000.0/animator.fps >= animatorTracker->second) {
                                animatorTracker->second = 0;
                                animate(animator);
                            }
                        }
                    }
                private:
                    std::map<Animator*,double> _animatorTracking {};
                    static void animate(Animator& animator) {
                        if (animator.sprites.empty()) return; // Only works if animator isn't empty
                        // Find current active sprite
                        int activeSpritePosition = -1;
                        for (int i = 0; i < animator.sprites.size(); ++i) {
                            if (animator.sprites[i]->active) {
                                animator.sprites[i]->active = false;
                                activeSpritePosition = i;
                                break;
                            }
                        }
                        if (++activeSpritePosition >= animator.sprites.size()) activeSpritePosition = 0;
                        // Only next active sprite should be active
                        for (auto& sprite: animator.sprites) {
                            sprite->active = false;
                        }
                        animator.sprites[activeSpritePosition]->active = true;
                    }
            };
            AnimatorHelper _animatorHelper {};
    };
}
