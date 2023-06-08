//
// Created by MisThe on 2023/6/3.
//

#ifndef CANVAS_1_0_GRAPHICDATA_H
#define CANVAS_1_0_GRAPHICDATA_H


#include "../../Framework/CustomPtr.h"
#include "../../../General/Container/Queue.h"

class Renderer;
class GraphicCore;
class GraphicData : public CustomPtr
{
public:
    GraphicData();
protected:
    void CustomMark() override;
public:
    Queue<Renderer*>* renderers;
    GraphicCore* core;
};


#endif //CANVAS_1_0_GRAPHICDATA_H
