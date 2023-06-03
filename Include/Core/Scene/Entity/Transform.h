//
// Created by MisThe on 2023/5/28.
//

#ifndef CANVAS_1_0_TRANSFORM_H
#define CANVAS_1_0_TRANSFORM_H

#include "../../Invoker/Component/Component.h"

class Transform : public Component {
public:
    void Initial() override;
    void OnEnable() override;
    void Invoke() override;
    void OnDisable() override;
    void Destroy() override;
public:
    std::string Type() override;
protected:
    void CustomMark() override;
    ~Transform() override;
protected:
    void ComponentRead(cereal::BinaryInputArchive &archive) override;
    void ComponentWrite(cereal::BinaryOutputArchive &archive) override;
};

#endif //CANVAS_1_0_TRANSFORM_H
