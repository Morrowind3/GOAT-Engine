#include "Script_SummonGoat.hpp"
#include "../../../Enemies/Goat/Object_Goat.hpp"
#include "../../../../Layers.hpp"

using namespace Engine;

Script_SummonGoat::Script_SummonGoat(Scene& scene, Object_Player& player, bool active): Script(active), _scene(scene), _player(player) { }

void Script_SummonGoat::onUpdate(double deltaTime) {
    // 3 key summons goat
    if (_input.getKeyDown(KeyCode::NUMBER_3)) {
        Transform transform{Point{_player.transform.position.x + 200, _player.transform.position.y - 200}, LAYER::TILES_FRONT, 1, 0, 4, 4};
        _scene.gameObjects.emplace_back(std::make_shared<Object_Goat>(transform, true));
    }
}