//
// Created by MisThe on 2023/5/28.
//

#include "../Include/Core/Asset/AssetManager.h"
#include "../Include/Core/Framework/Static.h"
#include "../Include/Core/Framework/ReflectFactory.h"
#include "../Include/General/String.h"

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
    //更新Cache数据
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
    this->Remove(asset->path);
}

void AssetManager::CustomMark() {
    CustomPtr::S_Mark(this->assetMap);
}

AssetManager::~AssetManager() {
    this->Clear();
}

void AssetManager::RefreshCache(std::string directory) {
    Queue<std::string>* paths = IO::ChildrenFiles(directory);
    paths->Push("CanvasOutput/Canvas/Assets/Texture/test.png");
    paths->IteratorWithout([this](std::string path) {
        //根据path生成cache
        std::string extension = IO::PathToExtension(path);
        std::string type = Static::S_SettingManager()->GetAssetSetting()->assetCacheMap->Get(extension);
        if (type.empty())
            return;
        std::string cache = path;
        String::Replace(cache,"/","_");
        String::Replace(cache, extension, type);
        cache = "Canvas/Cache/" + type + "/" + cache;
        if (IO::Exist(cache))
            return;
        Asset* ptr = dynamic_cast<Asset *>(ReflectFactory::S_Instance(type));
        ptr->path = cache;
        ptr->Cache(path);
        this->assetMap->Insert(cache, ptr);
        Debug::Info("Asset Manager", "Create New Cache [" + path + "]");
    });
}