//
// Created by MisThe on 2023/5/28.
//

#ifndef CANVAS_1_0_ASSETMANAGER_H
#define CANVAS_1_0_ASSETMANAGER_H

#include <fstream>
#include "Serialize.h"
#include "../../General/Container/Map.h"
#include "../../General/IO.h"
#include "../../General/Debug.h"
#include "Asset.h"

class AssetManager final : public CustomPtr
{
private:
    Map<std::string, Asset *> *assetMap = nullptr;
    Map<std::string, std::string> *assetCacheMap = nullptr;
public:
    AssetManager();
    void RefreshCache(std::string directory = "Asset");
protected:
    ~AssetManager() override;
public:
    template<class T> T *Create(std::string path) {
        if (IO::Exist(path)) {
            Debug::Warn("Asset Create","The Asset Existed [" + path + "]");
            return this->Instance<T>(path);
        }
        T* temp = new T();
        temp->name = IO::PathToName(path);
        temp->path = path;
        this->assetMap->Insert(path, temp);
        return temp;
    }
    template<class T> T *Instance(std::string path) {
        T *temp = dynamic_cast<T *>(this->assetMap->Get(path));
        if (temp != nullptr)
            return temp;
        std::ifstream is(path);
        try {
            if (is.is_open()) {
                cereal::BinaryInputArchive archive(is);
                temp = new T();
                archive(*temp);
            }
        } catch (...) {
            Debug::Warn("Asset Instance", "The Asset Format Does Not Match [" + path + "]");
        }
        is.close();
        if (temp == nullptr)
            return temp;
        temp->name = IO::PathToName(path);
        temp->path = path;
        this->assetMap->Insert(path, temp);
        return temp;
    }
    void Invoke();
    void Clear();
    void Remove(std::string path);
    void Remove(Asset *asset);
private:
    void Update(Asset *asset);
protected:
    void CustomMark() override;
};


#endif //CANVAS_1_0_ASSETMANAGER_H
