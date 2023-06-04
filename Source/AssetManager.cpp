//
// Created by MisThe on 2023/5/28.
//

#include "../Include/Core/Asset/AssetManager.h"

//void AssetManager::S_Config(AssetManager::AssetConfig config) {
////    if (AssetManager::assetMap == nullptr)
////      this->assetMap = new Map<std::string, Asset*>();
////    Framework::S_AddRoot(AssetManager::assetMap);
//}

AssetManager::AssetManager() {
    this->assetMap = new Map<std::string, Asset*>();
}

void AssetManager::Clear() {
  this->assetMap->Iterator([this](std::string path, Asset* asset) {
      this->Update(asset);
    });
  this->assetMap->Clear();
}

void AssetManager::Invoke() {

}

void AssetManager::Update(Asset *asset) {
    Debug::Info("Asset", "Update Asset [" + asset->path + "]");
    std::ofstream os(asset->path);
    if (os.is_open()) {
        cereal::BinaryOutputArchive archive(os);
        archive(*asset);
    }
    os.close();
}

void AssetManager::Remove(std::string path) {
    Asset* asset = AssetManager::assetMap->Get(path);
    if (asset == nullptr)
        return;
  this->assetMap->Remove(path);
  this->Update(asset);
}

void AssetManager::Remove(Asset *asset) {
    if (asset == nullptr)
        return;
    this->Remove(asset);
}

void AssetManager::CustomMark() {
    CustomPtr::S_Mark(this->assetMap);
}