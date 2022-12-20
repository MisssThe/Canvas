//
// Created by ZLX on 2022/12/20.
//

#include "../Head/Asset/Asset.h"
#include "../Head/Tool/Debug.h"

std::unordered_map<std::string, std::queue<Asset*>*> Asset::assets;
std::unordered_map<std::string, Asset*> Asset::updatedAssets;
int Asset::updateAssetThreshold = 16;

void Asset::Load(std::string path) {
    if (this->target == path) {
        Debug::Warm("repetitive path to load","load asset");
        return;
    }
    if (path.empty()) {
        Debug::Warm("error path to load","load asset");
        return;
    }
    this->target = path;
    if (assets.find(this->target) != assets.end() && !assets[this->target]->empty())
    {
        assets[this->target]->front()->Copy(this);
        assets[this->target]->push(this);
    }
    else
    {
        assets.insert(std::pair<std::string, std::queue<Asset*>*>(this->target,new std::queue<Asset*>()));
        assets[this->target]->push(this);
    }
}

void Asset::Update(bool whole) {
    if (target.empty()) {
        Debug::Warm("error path to load","update asset");
        return;
    }
    if (assets.find(this->target) == assets.end())
        return;

    if (whole)
    {
        std::queue<Asset*>* assetQueue = assets.find(this->target)->second;
        int size = assetQueue->size();
        for (int index = 0; index < size; ++index) {
            Asset* front = assetQueue->front();
            this->Copy(front);
            assetQueue->pop();
            assetQueue->push(front);
        }
    }
    if (updatedAssets.find(this->target) == updatedAssets.end())
        updatedAssets.insert(std::pair<std::string, Asset*>(target, this));
    updatedAssets[this->target] = this;
    if (updatedAssets.size() > updateAssetThreshold)
        Refresh();
}

void Asset::Release() {
    if (assets.find(this->target) == assets.end())
        return;
    std::queue<Asset*>* assetQueue = assets.find(this->target)->second;
    int size = assetQueue->size();
    for (int index = 0; index < size; ++index) {
        Asset* front = assetQueue->front();
        assetQueue->pop();
        if (front != this)
            assetQueue->push(front);
    }
    this->Clear();
}

void Asset::Refresh() {
    for (auto asset : updatedAssets) {
        asset.second->Write();
    }
}
