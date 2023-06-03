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

class AssetManager {
private:
    static Map<std::string, Asset *> *S_assetMap;
public:
    struct AssetConfig {

    };
public:
    static void S_Config(AssetConfig config);
    template<class T>
    static T *S_Create(std::string path) {
        if (IO::Exist(path)) {
            Debug::Warn("Asset Create","The Asset Existed [" + path + "]");
            return S_Instance<T>(path);
        }
        T* temp = new T();
        temp->name = IO::PathToName(path);
        temp->path = path;
        S_assetMap->Insert(path, temp);
        return temp;
    }
    template<class T>
    static T *S_Instance(std::string path) {
        T *temp = dynamic_cast<T *>(AssetManager::S_assetMap->Get(path));
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
        S_assetMap->Insert(path, temp);
        return temp;
    }
    static void S_Invoke();
    static void S_Clear();
    static void S_Release();
    static void S_Remove(std::string path);
    static void S_Remove(Asset *asset);
private:
    static void S_Update(Asset *asset);
};


#endif //CANVAS_1_0_ASSETMANAGER_H
