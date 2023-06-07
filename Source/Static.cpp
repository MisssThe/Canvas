//
// Created by MisThe on 2023/6/4.
//

#include "../Include/Core/Framework/Static.h"
#include "../Include/Core/Framework/GarbageCollection.h"

AssetManager* Static::S_assetManager = nullptr;
SettingManager* Static::S_settingManager = nullptr;
SceneManager* Static::S_sceneManager = nullptr;
Components* Static::S_components = nullptr;
Psycho* Static::S_psycho = nullptr;
Graphic* Static::S_graphic = nullptr;

void Static::S_Initial() {
    Static::S_assetManager = new AssetManager();
    Static::S_settingManager = new SettingManager();
    Static::S_components = new Components();
    Static::S_sceneManager = new SceneManager();
    Static::S_psycho = new Psycho();
    Static::S_graphic = new Graphic();

    GarbageCollection::S_AddRoot(Static::S_assetManager);
    GarbageCollection::S_AddRoot(Static::S_settingManager);
    GarbageCollection::S_AddRoot(Static::S_sceneManager);
    GarbageCollection::S_AddRoot(Static::S_components);
    GarbageCollection::S_AddRoot(Static::S_psycho);
    GarbageCollection::S_AddRoot(Static::S_graphic);
}

AssetManager *Static::S_AssetManager() {
    return Static::S_assetManager;
}

SettingManager *Static::S_SettingManager() {
    return Static::S_settingManager;
}

SceneManager *Static::S_SceneManager() {
    return Static::S_sceneManager;
}

Components *Static::S_Components() {
    return Static::S_components;
}

Psycho *Static::S_Psycho() {
    return Static::S_psycho;
}

Graphic *Static::S_Graphic() {
    return Static::S_graphic;
}
