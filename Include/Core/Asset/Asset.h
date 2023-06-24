//
// Created by MisThe on 2023/5/21.
//

#ifndef CANVAS_1_0_ASSET_H
#define CANVAS_1_0_ASSET_H

#include "Serialize.h"

class Asset : public Serialize {
public:
    std::string_view name;
    std::string_view path;
public:
    virtual void Cache(std::string_view file) {};
};


#endif //CANVAS_1_0_ASSET_H
