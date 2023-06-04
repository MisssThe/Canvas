//
// Created by MisThe on 2023/6/3.
//

#ifndef CANVAS_1_0_OPENGLGRAPHICCORE_H
#define CANVAS_1_0_OPENGLGRAPHICCORE_H


#include "GraphicCore.h"

class GLFWwindow;

class OpenGLGraphicCore : public GraphicCore
{
protected:
    void CustomMark() override;
public:
    void BeginFrame() override;
    void EndFrame() override;
public:
    OpenGLGraphicCore();
private:
    GLFWwindow* window;
};


#endif //CANVAS_1_0_OPENGLGRAPHICCORE_H
