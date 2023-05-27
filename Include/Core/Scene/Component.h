//
// Created by MisThe on 2023/5/25.
//

#ifndef CANVAS_1_0_COMPONENT_H
#define CANVAS_1_0_COMPONENT_H


#include "../Asset/Serialize.h"

class Component : public Serialize
{
protected:
    ~Component() override = default;
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
};


#endif //CANVAS_1_0_COMPONENT_H
