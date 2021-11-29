#include "SummonScript.hpp"
#include "../../../../GameObjects/Enemies/Goat.hpp"
#include "../../../../Layers.hpp"

using namespace Engine;

SummonScript::SummonScript(Scene& scene, Player& player, bool active): Script(active), _scene(scene), _player(player) { }

void SummonScript::onUpdate(double deltaTime) {
    // 4 key summons goat
    if (_input.getKeyDown(KeyCode::NUMBER_4)) {
        Transform transform{Point{_player.transform.position.x + 200, _player.transform.position.y - 200}, LAYER::TILES_FRONT, 0, 5, 5};
        _scene.gameObjects.emplace_back(std::make_shared<Goat>(transform, true));
    }
}