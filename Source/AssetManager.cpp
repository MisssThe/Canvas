//
// Created by MisThe on 2023/5/28.
//

#include "../Include/Core/Asset/AssetManager.h"
#include "../Include/Core/GarbageCollection/GarbageCollection.h"


Map<std::string, Asset*>* AssetManager::S_assetMap = nullptr;

void AssetManager::S_Config(AssetManager::AssetConfig config) {
    if (AssetManager::S_assetMap == nullptr)
        AssetManager::S_assetMap = new Map<std::string, Asset*>();
    GarbageCollection::S_AddRoot(AssetManager::S_assetMap);
}

void AssetManager::S_Release() {
    AssetManager::S_Clear();
    AssetManager::S_assetMap = nullptr;
}

void AssetManager::S_Clear() {
    AssetManager::S_assetMap->Iterator([](std::string path, Asset* asset) {
        AssetManager::S_Update(asset);
    });
    AssetManager::S_assetMap->Clear();
}

void AssetManager::S_Invoke() {

}

void AssetManager::S_Update(Asset *asset) {
    Debug::Info("Asset", "Update Asset [" + asset->path + "]");
    std::ofstream os(asset->path);
    if (os.is_open()) {
        cereal::BinaryOutputArchive archive(os);
        archive(*asset);
    }
    os.close();
}

void AssetManager::S_Remove(std::string path) {
    Asset* asset = AssetManager::S_assetMap->Get(path);
    if (asset == nullptr)
        return;
    AssetManager::S_assetMap->Remove(path);
    AssetManager::S_Update(asset);
}
