//
// Created by Morrowind3 on 08/12/2021.
//

#include "Cloud.hpp"
#include "../../../Keys.hpp"
#include "CloudBehavior.hpp"
#include "../../../Layers.hpp"

Cloud::Cloud(Cloud::Shape shape, Transform transform, bool active) : GameObject(transform, active){
    std::string sprite = "Sprites/utils/skydecor/";
    switch(shape){
        case Shape::BIG: sprite.append("cloud_big.png");
        break;
        case Shape::SMALL: sprite.append("cloud_small.png");
        break;
        case Shape::WIDE: sprite.append("cloud_wide.png");
        break;
    }
    sprites.insert(std::make_pair(Keys::CLOUDS, Sprite{sprite, true}));
    behaviors.insert(std::make_pair(Keys::CLOUDS, std::make_shared<CloudBehavior>(*this, true)));


}
