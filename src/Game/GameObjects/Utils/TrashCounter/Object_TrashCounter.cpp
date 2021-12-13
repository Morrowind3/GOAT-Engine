#include "Object_TrashCounter.hpp"
#include "../../../Keys.hpp"
#include "../../../Layers.hpp"
#include "../Timer/Behavior_Timer.hpp"
#include "Behavior_TrashCounter.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "Sprites/Sprite_Trash0.hpp"
#include "Sprites/Sprite_Trash1.hpp"
#include "Sprites/Sprite_Trash2.hpp"
#include "Sprites/Sprite_Trash3.hpp"
#include "../../WorldObjects/Trash/Animator_Trash.hpp"

Object_TrashCounter::Object_TrashCounter(bool active) : GameObject(Transform{{1150, 12}, LAYER::UI, 1, 2, 2}, active) {
    auto& trash0 = sprites.insert(std::make_pair(Keys::TRASH_0, Sprite_Trash0{true})).first->second;
    auto& trash1 = sprites.insert(std::make_pair(Keys::TRASH_1, Sprite_Trash1{false})).first->second;
    auto& trash2 = sprites.insert(std::make_pair(Keys::TRASH_2, Sprite_Trash2{false})).first->second;
    auto& trash3 = sprites.insert(std::make_pair(Keys::TRASH_3, Sprite_Trash3{false})).first->second;
    animators.insert(std::make_pair(Keys::ANIMATOR, Animator_Trash{trash0,trash1,trash2,trash3,true}));

    Point textPos = transform.position;
    textPos.y -= 2;
    textPos.x += 70;

    text.insert(std::make_pair(Keys::TRASH, Text{"00", "Fonts/Symtext.ttf", 48,
                                                 Color{0, 0, 0, 255},
                                                 Transform{textPos, LAYER::UI}, true}));
    behaviors.insert(std::make_pair(Keys::TRASH, std::make_shared<Behavior_TrashCounter>(text.at(Keys::TRASH), true)));
}
