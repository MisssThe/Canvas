//
// Created by MisThe on 2023/6/3.
//

#ifndef CANVAS_1_0_GRAPHICSETTING_H
#define CANVAS_1_0_GRAPHICSETTING_H

#include "Setting.h"

class GraphicSetting : public Setting
{
public:
    enum GraphicType
    {
        OpenGL,DXD,Metal,Vulkan
    };
public:
    GraphicType graphicType;
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
    ~GraphicSetting() override;
};


#endif //CANVAS_1_0_GRAPHICSETTING_H
