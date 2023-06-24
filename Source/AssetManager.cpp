//
// Created by MisThe on 2023/5/28.
//

#include "../Include/Core/Asset/AssetManager.h"
#include "../Include/Core/Framework/Static.h"
#include "../Include/Core/Framework/ReflectFactory.h"
#include "../Include/General/Tool/String.h"

AssetManager::AssetManager() {
    this->assetMap = new Map<std::string_view, Asset*>();
    //检查文件目录是否存在，不存在则创建
    /**
     * CanvasOutput
     *      Art
     *          Scene
     *          Material
     *          Shader
     *          Mesh
     *          Texture
     *          Animation
     *      Setting
     **/
}

void AssetManager::Clear() {
  this->assetMap->Iterator([this](const std::string_view& path, Asset* asset) {
      this->Update(asset);
    });
  this->assetMap->Clear();
}

void AssetManager::Invoke() {
    //更新Cache数据
}

void AssetManager::Update(Asset *asset) {
    Debug::Info("Asset", {"Update Asset [", asset->path, "]"});
    std::ofstream os(asset->path);
    if (os.is_open()) {
        cereal::BinaryOutputArchive archive(os);
        archive(*asset);
    }
    os.close();
}

void AssetManager::Remove(std::string_view path) {
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

void AssetManager::RefreshCache(const std::string_view& directory) {
    if (this->assetMap == nullptr)
        return;
    Queue<std::string_view> *paths = IO::ChildrenFiles(directory);
    paths->IteratorWithout([this](std::string_view path) {
        //根据path生成cache
        std::string_view extension = IO::PathToExtension(path);
        std::string type(Static::S_SettingManager()->GetAssetSetting()->assetCacheMap->Get(extension));
        if (type.empty())
            return;
        std::string_view cache = path;
        String::ReplaceAll(cache, "/", "_");
        String::ReplaceAll(cache, extension, type);
        cache = String::Combine({"Canvas/Caches/", type, "/", std::string(cache)});
        if (IO::Exist(cache))
            return;
        Asset *ptr = dynamic_cast<Asset *>(ReflectFactory::S_Instance(type));
        ptr->path = cache;
        ptr->Cache(path);
        this->assetMap->Insert(cache, ptr);
        Debug::Info("Asset Manager", {"Create New Cache [", path, "]"});
    });
}

void AssetManager::SetInfo(Asset *asset, std::string_view &path) {
    asset->name = IO::PathToName(path);
    asset->path = path;
    this->assetMap->Insert(path, asset);
}
