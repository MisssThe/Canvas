//
// Created by MisThe on 2023/5/21.
//

#ifndef CANVAS_1_0_ASSET_H
#define CANVAS_1_0_ASSET_H

#include "Serialize.h"

class Asset : public Serialize {
public:
    std::string name;
    std::string path;
public:
    virtual void Cache(std::string file) {};
};


#endif //CANVAS_1_0_ASSET_H
