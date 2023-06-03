//
// Created by MisThe on 2023/5/30.
//

#ifndef CANVAS_1_0_SCENEMANAGER_H
#define CANVAS_1_0_SCENEMANAGER_H

#include "Scene.h"
#include "../Asset/AssetManager.h"

class SceneManager {
public:
    struct SceneManagerConfig
    {
    public:
        std::string editorScenePath;
    };
public:
    static void S_Config(SceneManagerConfig config);
    static Scene* S_Load(std::string path, bool single = true);
    static void S_Unload(std::string path);
    static void S_Unload(Scene* scene);
private:
    static Queue<std::string>* S_scenes;
private:
    SceneManager() = delete;
    static void S_OnlyUnload(std::string path);
};


#endif //CANVAS_1_0_SCENEMANAGER_H
