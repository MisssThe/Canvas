//
// Created by MisThe on 2023/5/21.
// 尽量不要序列化指针除了Asset
// 严禁序列化指针相互引用
//

#ifndef CANVAS_1_0_SERIALIZE_H
#define CANVAS_1_0_SERIALIZE_H

#include <cereal/archives/binary.hpp>
#include "../../Core/GarbageCollection/CustomPtr.h"

class Serialize : public CustomPtr
{
public:
    void serialize(cereal::BinaryInputArchive& archive);
    void serialize(cereal::BinaryOutputArchive& archive);
protected:
    virtual void Read(cereal::BinaryInputArchive& archive) = 0;
    virtual void Write(cereal::BinaryOutputArchive& archive) = 0;
protected:
    void Archive(cereal::BinaryInputArchive& archive,Serialize* ptr);
//    template<typename T> void Archive(cereal::BinaryInputArchive& archive, T temp)
//    {
//        archive(temp);
//    }
};


#endif //CANVAS_1_0_SERIALIZE_H
