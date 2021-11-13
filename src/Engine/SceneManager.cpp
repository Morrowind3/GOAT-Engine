#include "SceneManager.hpp"

using namespace Engine;

SceneManager::SceneManager(const std::vector<Scene>& scenes) : _scenes(scenes)
{    
}

const Scene& SceneManager::Current() const
{
    return _scenes.at(0);
}
