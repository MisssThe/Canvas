//
// Created by MisThe on 2023/5/21.
//

#include "../Include/Core/Asset/Asset.h"
#include "../Include/Core/GarbageCollection/GarbageCollection.h"

//会泄漏一个map
Map<std::string, Asset*>* Asset::_assetMap = nullptr;

void Asset::CustomMark() {
    Asset::_assetMap->Mark();
}

Asset::Asset() {
    if (Asset::_assetMap != nullptr)
        return;
    Asset::_assetMap = new Map<std::string, Asset *>();
    GarbageCollection::AddRoot(Asset::_assetMap);
}

void Asset::S_Destroy() {

}

void Asset::S_Clear() {
    Asset::_assetMap->Clear();
}
