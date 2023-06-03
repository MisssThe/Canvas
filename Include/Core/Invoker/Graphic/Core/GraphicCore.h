//
// Created by MisThe on 2023/6/3.
//

#ifndef CANVAS_1_0_GRAPHICCORE_H
#define CANVAS_1_0_GRAPHICCORE_H


#include "../GraphicData.h"

class GraphicCore {
public:
    virtual void Invoke(GraphicData* data) = 0;
};


#endif //CANVAS_1_0_GRAPHICCORE_H
