//
// Created by MisThe on 2023/5/22.
//

#ifndef CANVAS_1_0_TRANSFORM_H
#define CANVAS_1_0_TRANSFORM_H


#include "../Asset/Serialize.h"

class Transform : public Serialize {
public:
protected:
    ~Transform() override = default;
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
};


#endif //CANVAS_1_0_TRANSFORM_H
