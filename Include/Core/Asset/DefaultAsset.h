//
// Created by MisThe on 2023/5/23.
//

#ifndef CANVAS_1_0_DEFAULTASSET_H
#define CANVAS_1_0_DEFAULTASSET_H


#include "Asset.h"

class DefaultAsset : public Asset
{
public:
    void Construct() override;
protected:
    void CustomMark() override;
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    ~DefaultAsset() override = default;
};


#endif //CANVAS_1_0_DEFAULTASSET_H
