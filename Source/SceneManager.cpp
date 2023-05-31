//
// Created by MisThe on 2023/5/30.
//

#include "../Include/Core/Scene/SceneManager.h"

Queue<std::string>* SceneManager::S_scenes = nullptr;

void SceneManager::S_Config(SceneManagerConfig config) {
    if (SceneManager::S_scenes == nullptr)
        SceneManager::S_scenes = new Queue<std::string>();
    SceneManager::S_Load(config.editorScenePath);
    SceneManager::S_scenes->Remove(config.editorScenePath);
}

Scene *SceneManager::S_Load(std::string path, bool single) {
    Scene* scene = Asset::S_Create<Scene>(path);
    if (single)
    {
        SceneManager::S_scenes->IteratorWithRemove([](std::string path) {
           SceneManager::S_OnlyUnload(path);
            return false;
        });
    }
    SceneManager::S_scenes->Push(path);
    return scene;
}

void SceneManager::S_Unload(std::string path) {
    if (path.empty())
        return;
    if (SceneManager::S_scenes == nullptr)
        return;
    if (!SceneManager::S_scenes->Contain(path))
        return;
    SceneManager::S_scenes->Remove(path);
    SceneManager::S_OnlyUnload(path);
}

void SceneManager::S_Unload(Scene *scene) {
    if (scene == nullptr)
        return;
    SceneManager::S_Unload(scene->path);
}

void SceneManager::S_OnlyUnload(std::string path) {
    Scene* scene = Asset::S_Instance<Scene>(path);
    if (scene == nullptr)
        return;
    scene->Unload();
    Asset::S_Remove(path);
}
