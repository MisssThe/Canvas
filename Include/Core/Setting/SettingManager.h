//
// Created by MisThe on 2023/6/3.
//

#ifndef CANVAS_1_0_SETTINGMANAGER_H
#define CANVAS_1_0_SETTINGMANAGER_H


#include "GraphicSetting.h"
#include "SceneSetting.h"
#include "AssetSetting.h"

class SettingManager : public CustomPtr
{
private:
    GraphicSetting* graphicSetting;
    SceneSetting* sceneSetting;
    AssetSetting* assetSetting;
public:
    SettingManager();
protected:
    void CustomMark() override;
public:
    GraphicSetting* GetGraphicSetting();
    SceneSetting* GetSceneSetting();
    AssetSetting* GetAssetSetting();
};


#endif //CANVAS_1_0_SETTINGMANAGER_H
