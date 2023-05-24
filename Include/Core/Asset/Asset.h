//
// Created by MisThe on 2023/5/21.
//

#ifndef CANVAS_1_0_ASSET_H
#define CANVAS_1_0_ASSET_H


#include <fstream>
#include "Serialize.h"
#include "../../General/Container/Map.h"

class Asset : public Serialize
{
private:
    static Map<std::string, Asset*>* _assetMap;
protected:
    Asset();
    ~Asset() override = default;
    void CustomMark() override;
public:
    std::string name;
public:
    virtual void Construct() = 0;
public:
    template<class T> static T* S_Instance(std::string path) {
        if (Asset::_assetMap == nullptr)
            Asset::_assetMap = new Map<std::string, Asset*>();
        T* temp = dynamic_cast<T*>(Asset::_assetMap->Get(path));
        if (temp != nullptr)
            return temp;
        temp = new T();
        std::ifstream is(path);
        if (is.is_open()) {
            cereal::BinaryInputArchive archive(is);
            temp = new T();
            archive(*temp);
        } else
            temp->Construct();
        is.close();
        temp->name = "aaa";
        _assetMap->Insert(path, temp);
        return temp;
    }
    static void S_Clear();
    static void S_Destroy();
};


#endif //CANVAS_1_0_ASSET_H
