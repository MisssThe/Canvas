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
    bool isSync;
    int width,height;
    std::string windowName;
    bool useBoard;
    bool useTransparent;
    std::string featurePath;
public:
    GraphicSetting();
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
};


#endif //CANVAS_1_0_GRAPHICSETTING_H
