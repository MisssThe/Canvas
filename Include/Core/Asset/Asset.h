//
// Created by MisThe on 2023/5/21.
//

#ifndef CANVAS_1_0_ASSET_H
#define CANVAS_1_0_ASSET_H


#include <fstream>
#include "Serialize.h"
#include "../../General/Container/Map.h"
#include "../../General/IO.h"

class Asset : public Serialize
{
private:
    static Map<std::string, Asset*>* S_assetMap;
public:
    Asset();
protected:
    ~Asset() override = default;
    void CustomMark() override;
public:
    virtual void Construct() = 0;
public:
    std::string name;
    std::string path;
    struct AssetConfig
    {

    };
public:
    static void S_Config(AssetConfig config);
    template<class T> static T* S_Instance(std::string path) {
        T* temp = dynamic_cast<T*>(Asset::S_assetMap->Get(path));
        if (temp != nullptr)
            return temp;
        temp = new T();
        std::ifstream is(path);
        bool success = is.is_open();
        try {
            if (success) {
                cereal::BinaryInputArchive archive(is);
                temp = new T();
                archive(*temp);
            }
        } catch (...) {
            success = false;
        }
        is.close();
        if (!success)
            temp->Construct();
        temp->name = IO::PathToName(path);
        temp->path = path;
        S_assetMap->Insert(path, temp);
        return temp;
    }
    static void S_Invoke();
    static void S_Clear();
    static void S_Destroy();
private:
    static void S_Update(Asset* asset);
};


#endif //CANVAS_1_0_ASSET_H
