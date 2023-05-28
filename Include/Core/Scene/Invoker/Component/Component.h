//
// Created by MisThe on 2023/5/25.
//

#ifndef CANVAS_1_0_COMPONENT_H
#define CANVAS_1_0_COMPONENT_H


#include "../../../Asset/Serialize.h"

class Component : public Serialize
{
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
public:
    virtual void Initial() = 0;
    virtual void OnEnable() = 0;
    virtual void Invoke() = 0;
    virtual void OnDisable() = 0;
    virtual void Destroy() = 0;
public:
    bool enable;
    bool destroy;
};


#endif //CANVAS_1_0_COMPONENT_H
