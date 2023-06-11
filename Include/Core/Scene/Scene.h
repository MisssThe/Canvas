//
// Created by MisThe on 2023/5/22.
//

#ifndef CANVAS_1_0_SCENE_H
#define CANVAS_1_0_SCENE_H


#include "../Asset/Asset.h"
#include "Entity/Entity.h"
#include "SceneInfo.h"

class Scene : public Asset
{
protected:
    void CustomMark() override;
    ~Scene() override = default;
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
public:
    Scene();
    void Load();
    void Unload();
    void ClearEntity();
    Entity* Root();
private:
    SceneInfo* info;
};


#endif //CANVAS_1_0_SCENE_H
