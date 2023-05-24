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
private:
    void InitGarbageCollection();
};


#endif //CANVAS_1_0_CANVAS_H
