//
// Created by MisThe on 2023/6/4.
//

#ifndef CANVAS_1_0_STATIC_H
#define CANVAS_1_0_STATIC_H


#include "CustomPtr.h"
#include "../Asset/AssetManager.h"
#include "../Scene/SceneManager.h"
#include "../Setting/SettingManager.h"
#include "../Invoker/Component/Components.h"
#include "../Invoker/Psycho/Psycho.h"
#include "../Invoker/Graphic/Graphic.h"

class Static final
{
public:
    Static() = delete;
    ~Static() = delete;
public:
    static void S_Initial();
    static AssetManager* S_AssetManager();
    static SettingManager* S_SettingManager();
    static SceneManager* S_SceneManager();
    static Components* S_Components();
    static Psycho* S_Psycho();
    static Graphic* S_Graphic();
private:
    static AssetManager* S_assetManager;
    static SettingManager* S_settingManager;
    static SceneManager* S_sceneManager;
    static Components* S_components;
    static Psycho* S_psycho;
    static Graphic* S_graphic;
};


#endif //CANVAS_1_0_STATIC_H
