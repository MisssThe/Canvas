//
// Created by MisThe on 2023/5/28.
//

#ifndef CANVAS_1_0_ASSETMANAGER_H
#define CANVAS_1_0_ASSETMANAGER_H

#include <fstream>
#include "Serialize.h"
#include "../../General/Container/Map.h"
#include "../../General/Tool/IO.h"
#include "../../General/Tool/Debug.h"
#include "Asset.h"
#include "../../General/Tool/String.h"

class AssetManager final : public CustomPtr
{
private:
    Map<std::string_view, Asset *> *assetMap = nullptr;
public:
    AssetManager();
    void RefreshCache(const std::string_view& directory = "Canvas/Assets");
protected:
    ~AssetManager() override;
public:
    template<class T> T *Create(std::string_view path) {
        T* temp = this->Instance<T>(path);
        if (temp != nullptr) {
            Debug::Warn("Asset Create", {"The Asset Existed [",path,"]"});
            return temp;
        }
        temp = new T();
        this->SetInfo(temp, path);
        return temp;
    }
    template<class T> T *Instance(std::string_view path) {
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
            Debug::Warn("Asset Instance", {"The Asset Format Does Not Match [", path, "]"});
        }
        is.close();
        if (temp == nullptr)
            return temp;
        this->SetInfo(temp, path);
        return temp;
    }
    void Invoke();
    void Clear();
    void Remove(std::string_view path);
    void Remove(Asset *asset);
private:
    void Update(Asset *asset);
    void SetInfo(Asset* asset, std::string_view& path);
protected:
    void CustomMark() override;
};


#endif //CANVAS_1_0_ASSETMANAGER_H
