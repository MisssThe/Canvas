//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Core/Asset/Asset.h"
#include "../Include/Core/GarbageCollection/GarbageCollection.h"
#include "../Include/General/Debug.h"

//会泄漏一个map
Map<std::string, Asset*>* Asset::S_assetMap = nullptr;

void Asset::CustomMark() {
    CustomPtr::S_Mark(Asset::S_assetMap);
}

Asset::Asset() {
    if (Asset::S_assetMap != nullptr)
        return;
    Asset::S_assetMap = new Map<std::string, Asset *>();
}

void Asset::S_Config(Asset::AssetConfig config) {
    if (Asset::S_assetMap == nullptr)
        Asset::S_assetMap = new Map<std::string, Asset*>();
    GarbageCollection::S_AddRoot(Asset::S_assetMap);
}

void Asset::S_Destroy() {
    Asset::S_Clear();
    Asset::S_assetMap = nullptr;
}

void Asset::S_Clear() {
    Asset::S_assetMap->Iterator([](std::string path, Asset* asset) {
        Asset::S_Update(asset);
    });
    Asset::S_assetMap->Clear();
}

void Asset::S_Invoke() {

}

void Asset::S_Update(Asset *asset) {
    Debug::Info("Asset", "Update Asset [" + asset->path + "]");
    std::ofstream os(asset->path);
    if (os.is_open()) {
        cereal::BinaryOutputArchive archive(os);
        archive(*asset);
    }
    os.close();
}
