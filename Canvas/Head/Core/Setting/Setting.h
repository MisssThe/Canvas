//
// Created by ZLX on 2022/12/19.
//

#ifndef CANVAS_SETTING_H
#define CANVAS_SETTING_H

#include <string>
#include "../../Asset/Asset.h"

class Setting {
public:
    static void Start();
    static void Pause();
    static void Restart();
    static void Stop();
public:
    enum GraphicAPI
    {
        DXD,OPENGL,VULKAN
    };
private:
    class SettingAsset : public Asset
    {

    };
};


#endif //CANVAS_SETTING_H
