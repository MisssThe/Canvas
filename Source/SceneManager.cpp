//
// Created by MisThe on 2023/5/30.
//

#include "../Include/Core/Scene/SceneManager.h"
#include "../Include/Core/Framework/Static.h"

void SceneManager::CustomMark() {
    CustomPtr::S_Mark(this->scenes);
}

SceneManager::SceneManager() {
    this->scenes = new Queue<std::string>();
    //加载editor场景
    SceneSetting* setting = Static::S_SettingManager()->GetSceneSetting();
    this->editorScene = this->Load(setting->editorScenePath);
    this->scenes->Remove(setting->editorScenePath);
    this->activeScene = this->Load(setting->activeScenePath);
}

Scene *SceneManager::Load(std::string path, bool single) {
    Scene* scene = Static::S_AssetManager()->Create<Scene>(path);
    if (single)
    {
        this->scenes->IteratorWithRemove([this](std::string path) {
            this->OnlyUnload(path);
            return false;
        });
    }
    this->scenes->Push(path);
    return scene;
}

void SceneManager::Unload(std::string path) {
    if (path.empty())
        return;
    if (this->scenes == nullptr)
        return;
    if (!this->scenes->Contain(path))
        return;
    this->scenes->Remove(path);
    this->OnlyUnload(path);
}

void SceneManager::Unload(Scene *scene) {
    if (scene == nullptr)
        return;
    this->Unload(scene->path);
}

void SceneManager::OnlyUnload(std::string path) {
    Scene* scene = Static::S_AssetManager()->Instance<Scene>(path);
    if (scene == nullptr)
        return;
    scene->Unload();
    Static::S_AssetManager()->Remove(path);
}

Scene *SceneManager::Editor() {
    return editorScene;
}

Scene *SceneManager::Active() {
    return activeScene;
}
