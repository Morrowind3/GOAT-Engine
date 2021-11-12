#include "Engine.hpp"

#include "../systems/RenderingSystem.hpp"

Engine::Engine() {
    addSystem<RenderingSystem>();
}