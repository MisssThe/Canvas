//
// Created by MisThe on 2023/6/3.
//

#ifndef CANVAS_1_0_OPENGLGRAPHICCORE_H
#define CANVAS_1_0_OPENGLGRAPHICCORE_H


#include "GraphicCore.h"

class OpenGLGraphicCore : public GraphicCore
{
public:
    void Invoke(GraphicData* data) override;
};


#endif //CANVAS_1_0_OPENGLGRAPHICCORE_H
