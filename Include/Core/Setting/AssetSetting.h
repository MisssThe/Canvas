//
// Created by MisThe on 2023/6/17.
//

#ifndef CANVAS_1_0_ASSETSETTING_H
#define CANVAS_1_0_ASSETSETTING_H

#include "../Asset/Asset.h"
#include "../../General/Container/Map.h"

class AssetSetting : public Asset {
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
    ~AssetSetting() override = default;
public:
    AssetSetting();
public:
    Map<std::string, std::string>* assetCacheMap = nullptr;
};


#endif //CANVAS_1_0_ASSETSETTING_H
