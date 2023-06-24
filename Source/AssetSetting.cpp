//
// Created by MisThe on 2023/6/17.
//

#include "../Include/Core/Setting/AssetSetting.h"
#include "../Include/General/Container/ContainSerialize/MapSerialize.h"
#include "../Include/General/Tool/String.h"

void AssetSetting::Read(cereal::BinaryInputArchive &archive) {
    this->assetCacheMap->Clear();
    std::function<void(std::string_view &, std::string_view &)> func = [&archive](std::string_view &extension,
                                                                                  std::string_view &type) {
        auto result = String::Read(archive, 2);
        extension = result->Pop();
        type = result->Pop();
    };
    MapSerialize::Read(archive, this->assetCacheMap, func);
}

void AssetSetting::Write(cereal::BinaryOutputArchive &archive) {
    std::function<void(std::string_view &, std::string_view &)> func = [&archive](std::string_view &extension,
                                                                                  std::string_view &type) {
        String::Write(archive, {extension, type});
    };
    MapSerialize::Write(archive, this->assetCacheMap, func);
}

void AssetSetting::CustomMark() {
    CustomPtr::S_Mark(this->assetCacheMap);
}

AssetSetting::AssetSetting() {
    this->assetCacheMap = new Map<std::string_view , std::string_view>("");
}
