//
// Created by MisThe on 2023/5/25.
//

#ifndef CANVAS_1_0_ENTITY_H
#define CANVAS_1_0_ENTITY_H


#include "../Asset/Serialize.h"
#include "../../General/Container/Queue.h"
#include "Component.h"

class Entity : public Serialize
{
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
    ~Entity() override;
public:
    std::string name;
    Queue<Component*>* components;
};


#endif //CANVAS_1_0_ENTITY_H
