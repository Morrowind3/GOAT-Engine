#pragma once

enum class GameComponentType
{
    SPRITE
};

struct GameComponent {
    GameComponentType type;
    bool active;
    
    GameComponent(GameComponentType type, bool active);
};