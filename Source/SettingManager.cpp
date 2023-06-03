//
// Created by MisThe on 2023/6/3.
//

#include "../Include/Core/Setting/SettingManager.h"
#include "../Include/Core/Asset/AssetManager.h"

GraphicSetting* SettingManager::graphicSetting = nullptr;

GraphicSetting *SettingManager::GetGraphicSetting() {
    if (SettingManager::graphicSetting == nullptr)
        SettingManager::graphicSetting = AssetManager::S_Create<GraphicSetting>("Canvas/Setting/graphic.setting");
    return SettingManager::graphicSetting;
}
