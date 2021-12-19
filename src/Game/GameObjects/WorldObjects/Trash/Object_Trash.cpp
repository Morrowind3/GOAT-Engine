#include "Object_Trash.hpp"
#include "../../../Keys.hpp"
#include "Behavior_Trash.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include <random>
#include <chrono>

Object_Trash::Object_Trash(Transform transform, bool active) : GameObject(transform, active) {
    behaviors.insert(std::make_pair(Keys::TRASH, std::make_shared<Behavior_Trash>(*this, true)));
    tags.emplace(Keys::TRASH, true);
    rigidBody = RigidBody(0, 0, BodyType::STATIC, true);
    collider = BoxCollider(30 * transform.scaleWidth, 30 * transform.scaleHeight, 0,0,0,0,true, true);
    audioSources.insert(std::make_pair(Keys::TRASH, AudioSource{"Sounds/PickUp.ogg", AudioSourceType::SAMPLE, true}));

    // Pick random sprite for trash object
    const static std::vector<std::string> SPRITE_OPTIONS = {
        "aluminiumcan",
        "beerbottle",
        "bottle",
        "chemical",
        "liquorbottle",
        "mug",
        "paintcan",
        "pizzabox",
        "sac",
        "tincan",
        "tunacan",
        "waterbottle"
    };
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> random(0,SPRITE_OPTIONS.size()-1);
    sprites.insert(std::make_pair(Keys::TRASH, Sprite{"Sprites/waste/waste_" + SPRITE_OPTIONS[random(generator)] + ".png",true}));
}
