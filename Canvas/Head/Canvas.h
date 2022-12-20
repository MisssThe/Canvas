//
// Created by ZLX on 2022/12/19.
//

#ifndef CANVAS_CANVAS_H
#define CANVAS_CANVAS_H

#include "Core/Platform/Platform.h"
#include "Core/Setting/Setting.h"
#include "Core/Graphic/Graphic.h"

class Canvas
{
public:
    static void Start()
    {
        //平台初始化
        Platform::Start();
        //设置模块启动
        Setting::Start();
        //拉起图形模块
        Graphic::Start();
    }
    static void Pause();
    static void Restart();
    static void Stop();
};

#endif //CANVAS_CANVAS_H
