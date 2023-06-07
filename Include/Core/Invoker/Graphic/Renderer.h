//
// Created by MisThe on 2023/6/8.
//

#ifndef CANVAS_1_0_RENDERER_H
#define CANVAS_1_0_RENDERER_H

#include "../Component/Component.h"
#include "Elements/Mesh.h"
#include "Elements/Material.h"

class Renderer : public Component
{
public:
    Mesh* mesh;
    Material* material;
public:
    void Initial() override;
    void OnEnable() override;
    void Invoke() override;
    void OnDisable() override;
    void Destroy() override;
    std::string Type() override;
protected:
    void ComponentRead(cereal::BinaryInputArchive &archive) override;
    void ComponentWrite(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
    ~Renderer() override = default;
};


#endif //CANVAS_1_0_RENDERER_H
