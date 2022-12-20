//
// Created by ZLX on 2022/12/20.
//

#ifndef CANVAS_ASSET_H
#define CANVAS_ASSET_H

#include <string>

class Asset {
public:
    void Load(std::string path);
    void Update(std::string path = "");
    void Release(std::string path = "");
private:
    std::string  path;
};


#endif //CANVAS_ASSET_H
