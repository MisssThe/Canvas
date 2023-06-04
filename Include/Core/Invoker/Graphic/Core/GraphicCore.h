//
// Created by MisThe on 2023/6/3.
//

#ifndef CANVAS_1_0_GRAPHICCORE_H
#define CANVAS_1_0_GRAPHICCORE_H


#include "../GraphicData.h"

class GraphicCore : public CustomPtr
{
public:
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
};


#endif //CANVAS_1_0_GRAPHICCORE_H
