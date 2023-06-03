//
// Created by MisThe on 2023/6/3.
//

#ifndef CANVAS_1_0_SETTINGMANAGER_H
#define CANVAS_1_0_SETTINGMANAGER_H


#include "GraphicSetting.h"

class SettingManager {
private:
    static GraphicSetting* graphicSetting;
private:
    SettingManager() = delete;
public:
    static GraphicSetting* GetGraphicSetting();
};


#endif //CANVAS_1_0_SETTINGMANAGER_H
