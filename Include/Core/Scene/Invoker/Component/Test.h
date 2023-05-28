//
// Created by MisThe on 2023/5/28.
//

#ifndef CANVAS_1_0_TEST_H
#define CANVAS_1_0_TEST_H


#include "Component.h"

class Test : public Component
{
public:
    void Initial() override;
    void OnEnable() override;
    void Invoke() override;
    void OnDisable() override;
    void Destroy() override;
protected:
    void CustomMark() override;
    ~Test() override;
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
};


#endif //CANVAS_1_0_TEST_H
