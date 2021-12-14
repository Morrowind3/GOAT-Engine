#include "Object_Cloud.hpp"
#include "../../../Keys.hpp"
#include "Behavior_Cloud.hpp"
#include "../../../Layers.hpp"

Object_Cloud::Object_Cloud(Object_Cloud::CloudShape shape, Transform transform, bool active) : GameObject(transform, active){
    std::string sprite = "Sprites/utils/skydecor/";
    switch(shape){
        case CloudShape::BIG: sprite.append("cloud_big.png");
        break;
        case CloudShape::SMALL: sprite.append("cloud_small.png");
        break;
        case CloudShape::WIDE: sprite.append("cloud_wide.png");
        break;
    }
    sprites.insert(std::make_pair(Keys::CLOUDS, Sprite{sprite, true}));
    behaviors.insert(std::make_pair(Keys::CLOUDS, std::make_shared<Behavior_Cloud>(*this, true)));
}
