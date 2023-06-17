//
// Created by MisThe on 2023/5/28.
//

#ifndef CANVAS_1_0_GRAPHIC_H
#define CANVAS_1_0_GRAPHIC_H


#include "Core/GraphicCore.h"
#include "GraphicData.h"
#include "Feature/GraphicFeatures.h"

class Graphic : public CustomPtr
{
public:
protected:
    void CustomMark() override;
public:
    Graphic();
    void Invoke();
private:
    void SetGraphicData();
private:
    GraphicCore* core = nullptr;
    GraphicData* data = nullptr;
    GraphicFeatures* features = nullptr;
};


#endif //CANVAS_1_0_GRAPHIC_H
