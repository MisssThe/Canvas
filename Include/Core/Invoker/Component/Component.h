//
// Created by MisThe on 2023/5/25.
//

#ifndef CANVAS_1_0_COMPONENT_H
#define CANVAS_1_0_COMPONENT_H


#include "../../Asset/Serialize.h"
#include "../../../General/Container/Map.h"

class Component : public Serialize
{
protected:
    void Read(cereal::BinaryInputArchive &archive) override final;
    void Write(cereal::BinaryOutputArchive &archive) override final;
    virtual void ComponentRead(cereal::BinaryInputArchive &archive) = 0;
    virtual void ComponentWrite(cereal::BinaryOutputArchive &archive) = 0;
public:
    virtual void Initial() = 0;
    virtual void OnEnable() = 0;
    virtual void Invoke() = 0;
    virtual void OnDisable() = 0;
    virtual void Destroy() = 0;
public:
    virtual std::string Type() = 0;
public:
    bool enable;
    bool destroy;
};

#endif //CANVAS_1_0_COMPONENT_H
