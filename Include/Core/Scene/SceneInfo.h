//
// Created by MisThe on 2023/6/11.
//

#ifndef CANVAS_1_0_SCENEINFO_H
#define CANVAS_1_0_SCENEINFO_H


#include "../Asset/Serialize.h"
#include "../Asset/Asset.h"
#include "Entity/Entity.h"

class SceneInfo : public Asset {
public:
    SceneInfo();
protected:
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
    ~SceneInfo() override = default;
public:
    Entity* root;
};


#endif //CANVAS_1_0_SCENEINFO_H
