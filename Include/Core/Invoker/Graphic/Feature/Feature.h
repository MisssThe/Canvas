//
// Created by MisThe on 2023/6/4.
//

#ifndef CANVAS_1_0_FEATURE_H
#define CANVAS_1_0_FEATURE_H


#include "../GraphicData.h"
#include "../../../Asset/Serialize.h"

class Feature : public Serialize
{
public:
    virtual void Prepare(GraphicData* data) = 0;
    virtual void Invoke(GraphicData* data) = 0;
//    virtual void End();
};


#endif //CANVAS_1_0_FEATURE_H
