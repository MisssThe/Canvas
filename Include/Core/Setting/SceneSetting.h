//
// Created by MisThe on 2023/6/4.
//

#ifndef CANVAS_1_0_SCENESETTING_H
#define CANVAS_1_0_SCENESETTING_H


#include "Setting.h"

class SceneSetting : public Setting
{
public:
    std::string editorScenePath;
    std::string activeScenePath;
public:
    SceneSetting();
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
};


#endif //CANVAS_1_0_SCENESETTING_H
