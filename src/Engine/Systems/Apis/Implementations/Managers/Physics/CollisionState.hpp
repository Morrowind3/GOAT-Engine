#ifndef GOAT_ENGINE_COLLISIONSTATE_HPP
#define GOAT_ENGINE_COLLISIONSTATE_HPP

enum class CollisionState {
    NOT_COLLIDING = 0,
    START_COLLIDING = 1,
    KEEP_COLLIDING = 2,
    STOP_COLLIDING = 3
};

#endif //GOAT_ENGINE_COLLISIONSTATE_HPP
