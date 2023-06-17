//
// Created by MisThe on 2023/6/17.
//

#include "../Include/Core/Setting/AssetSetting.h"
#include "../Include/General/Container/ContainSerialize/MapSerialize.h"

void AssetSetting::Read(cereal::BinaryInputArchive &archive) {
    std::function<void(std::string&,std::string&)> func = [&archive](std::string& extension,std::string& type) {
        archive(extension, type);
    };
    MapSerialize::Read(archive, this->assetCacheMap, func);
}

void AssetSetting::Write(cereal::BinaryOutputArchive &archive) {
    std::function<void(std::string&,std::string&)> func = [&archive](std::string& extension,std::string& type) {
        archive(extension, type);
    };
    MapSerialize::Write(archive, this->assetCacheMap, func);
}

void AssetSetting::CustomMark() {
    CustomPtr::S_Mark(this->assetCacheMap);
}

AssetSetting::AssetSetting() {
    this->assetCacheMap = new Map<std::string, std::string>();
}
