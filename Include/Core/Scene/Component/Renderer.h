//
// Created by MisThe on 2023/6/8.
//

#ifndef CANVAS_1_0_RENDERER_H
#define CANVAS_1_0_RENDERER_H

#include "../../Invoker/Component/Component.h"
#include "../../Invoker/Graphic/Elements/Mesh.h"
#include "../../Invoker/Graphic/Elements/Material.h"

class Renderer : public Component
{
public:
    Mesh* mesh;
    Material* material;
public:
    void OnInitial() override;
    void OnEnable() override;
    void OnInvoke() override;
    void OnDisable() override;
    void OnDestroy() override;
public:
    std::string_view Type() override;
    Queue<std::string_view> *RequireComponent() override;
protected:
    void ComponentRead(cereal::BinaryInputArchive &archive) override;
    void ComponentWrite(cereal::BinaryOutputArchive &archive) override;
    void CustomMark() override;
    ~Renderer() override = default;
};


#endif //CANVAS_1_0_RENDERER_H
