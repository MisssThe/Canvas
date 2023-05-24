//
// Created by MisThe on 2023/5/21.
//

#ifndef CANVAS_1_0_SERIALIZE_H
#define CANVAS_1_0_SERIALIZE_H

#include <cereal/archives/binary.hpp>
#include "../../Core/GarbageCollection/CustomPtr.h"

class Serialize : public CustomPtr
{
protected:
    ~Serialize() override = default;
public:
    void serialize(cereal::BinaryInputArchive& archive);
    void serialize(cereal::BinaryOutputArchive& archive);
protected:
    virtual void Read(cereal::BinaryInputArchive& archive) = 0;
    virtual void Write(cereal::BinaryOutputArchive& archive) = 0;
};


#endif //CANVAS_1_0_SERIALIZE_H
