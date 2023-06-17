//
// Created by MisThe on 2023/6/8.
//

#ifndef CANVAS_1_0_TEXTURE_H
#define CANVAS_1_0_TEXTURE_H


#include "../../../../Asset/Asset.h"

class Texture : public Asset {
public:
    std::string texturePath;
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
    ~Texture() override = default;
public:
    void Cache(std::string file) override;
};


#endif //CANVAS_1_0_TEXTURE_H
