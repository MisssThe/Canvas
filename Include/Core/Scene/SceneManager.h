//
// Created by MisThe on 2023/5/30.
//

#ifndef CANVAS_1_0_SCENEMANAGER_H
#define CANVAS_1_0_SCENEMANAGER_H

//#include "Scene.h"
#include "../Asset/AssetManager.h"
#include "Scene.h"

class SceneManager final : public CustomPtr
{
protected:
    void CustomMark() override;
public:
    SceneManager();
    void Initial();
    Scene* Editor();
    Scene* Active();
//    static void S_Config(SceneManagerConfig config);
    Scene* Load(std::string_view path, bool single = true);
    void Unload(std::string_view path);
    void Unload(Scene* scene);
private:
    Queue<std::string_view>* scenes;
private:
    void OnlyUnload(std::string_view path);
private:
    Scene* editorScene;
    Scene* activeScene;
};


#endif //CANVAS_1_0_SCENEMANAGER_H
