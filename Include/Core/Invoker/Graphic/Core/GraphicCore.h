//
// Created by MisThe on 2023/6/3.
//

#ifndef CANVAS_1_0_GRAPHICCORE_H
#define CANVAS_1_0_GRAPHICCORE_H


#include "../GraphicData.h"
#include "../Elements/Material.h"
#include "../Elements/Mesh.h"

class GraphicCore : public CustomPtr
{
public:
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
    void DrawScreen(Material* material);
    virtual void DrawRender(Mesh* mesh, Material* material) = 0;
    virtual void DrawRenderers() = 0;
};

#endif //CANVAS_1_0_GRAPHICCORE_H
