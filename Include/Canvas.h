//
// Created by MisThe on 2023/5/21.
// Canvas 启动接口
//

#ifndef CANVAS_1_0_CANVAS_H
#define CANVAS_1_0_CANVAS_H


#include "Core/Framework/CustomPtr.h"

class Canvas {
public:
    Canvas();
    ~Canvas();
    void Invoke();
public:
    static void S_Pause();
    static void S_Resume();
    static void S_Quit();
private:
    static bool S_notPause;
    static bool S_exist;
};


#endif //CANVAS_1_0_CANVAS_H
