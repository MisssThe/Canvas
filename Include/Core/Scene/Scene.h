//
// Created by MisThe on 2023/5/22.
//

#ifndef CANVAS_1_0_SCENE_H
#define CANVAS_1_0_SCENE_H


#include "../Asset/Asset.h"
#include "Entity/Entity.h"
class Scene : public Asset
{
protected:
    void CustomMark() override;
    void Read(cereal::BinaryInputArchive &archive) override;
    void Write(cereal::BinaryOutputArchive &archive) override;
    ~Scene() override;
public:
    Scene();
    void Load();
    void Unload();
    Entity* AddEntity(std::string name = "entity");
private:
    Entity* root;
};


#endif //CANVAS_1_0_SCENE_H
