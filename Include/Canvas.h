//
// Created by MisThe on 2023/5/21.
// Canvas 启动接口
//

#ifndef CANVAS_1_0_CANVAS_H
#define CANVAS_1_0_CANVAS_H


#include "Core/GarbageCollection/CustomPtr.h"
#include "Core/Scene/Scene.h"

class Canvas {
public:
    Canvas();
    ~Canvas();
    void Invoke();
public:
    static void S_Quit();
private:
    void InitAsset();
    void InitGarbageCollection();
    void InitThreadPool();
    void InitScene();
private:
    static bool S_exist;
};


#endif //CANVAS_1_0_CANVAS_H
