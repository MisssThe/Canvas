//
// Created by MisThe on 2023/6/4.
//

#ifndef CANVAS_1_0_MATERIAL_H
#define CANVAS_1_0_MATERIAL_H


#include "../../../Asset/Asset.h"
#include "Detail/Shader.h"

class Material : public Asset {
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
    ~Material() override = default;
public:
    Shader* shader;
    Queue<std::string> textureQueue;
    Queue<float> floatQueue;
};


#endif //CANVAS_1_0_MATERIAL_H
