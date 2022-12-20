//
// Created by ZLX on 2022/12/20.
//

#ifndef CANVAS_ASSET_H
#define CANVAS_ASSET_H

#include <string>
#include <unordered_map>
#include <queue>

class Asset {
public:
    void Load(std::string path);
    void Update(bool whole = true);
    void Release();
public:
    static void Refresh();
protected:
    virtual void Read() = 0;
    virtual void Write() = 0;
    virtual void Clear() = 0;
    virtual void Copy(Asset* asset) = 0;
private:
    std::string target;
private:
    static std::unordered_map<std::string, std::queue<Asset*>*> assets;
    static std::unordered_map<std::string, Asset*> updatedAssets;
    static int updateAssetThreshold;
};


#endif //CANVAS_ASSET_H
