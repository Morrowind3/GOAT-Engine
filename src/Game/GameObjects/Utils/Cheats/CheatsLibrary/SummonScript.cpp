#include "SummonScript.hpp"
#include "../../../Enemies/Goat/Goat.hpp"
#include "../../../../Layers.hpp"

using namespace Engine;

SummonScript::SummonScript(Scene& scene, Object_Player& player, bool active): Script(active), _scene(scene), _player(player) { }

void SummonScript::onUpdate(double deltaTime) {
    // 3 key summons goat
    if (_input.getKeyDown(KeyCode::NUMBER_3)) {
        Transform transform{Point{_player.transform.position.x + 200, _player.transform.position.y - 200}, LAYER::TILES_FRONT, 1, 0, 5, 5};
        _scene.gameObjects.emplace_back(std::make_shared<Goat>(transform, true));
    }
}