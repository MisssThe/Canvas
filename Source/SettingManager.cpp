//
// Created by MisThe on 2023/6/3.
//

#include "../Include/Core/Setting/SettingManager.h"
#include "../Include/Core/Asset/AssetManager.h"
#include "../Include/Core/Framework/Static.h"

SettingManager::SettingManager() {
    this->graphicSetting = Static::S_AssetManager()->Create<GraphicSetting>("Canvas/Setting/graphic.setting");
    this->sceneSetting = Static::S_AssetManager()->Create<SceneSetting>("Canvas/Setting/scene.setting");
}

void SettingManager::CustomMark() {
    CustomPtr::S_Mark(this->graphicSetting);
    CustomPtr::S_Mark(this->sceneSetting);
}

GraphicSetting *SettingManager::GetGraphicSetting() {
    return this->graphicSetting;
}

SceneSetting *SettingManager::GetSceneSetting() {
    return this->sceneSetting;
}
