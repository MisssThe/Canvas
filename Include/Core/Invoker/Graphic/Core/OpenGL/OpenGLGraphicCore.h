//
// Created by MisThe on 2023/6/3.
//

#ifndef CANVAS_1_0_OPENGLGRAPHICCORE_H
#define CANVAS_1_0_OPENGLGRAPHICCORE_H


#include "../GraphicCore.h"
#include "OpenGLMesh.h"
#include "OpenGLShader.h"
#include "../../../../../General/Container/Map.h"
#include "OpenGLTexture.h"

class GLFWwindow;

class OpenGLGraphicCore : public GraphicCore {
protected:
    void CustomMark() override;
public:
    void BeginFrame() override;
    void EndFrame() override;
public:
    OpenGLGraphicCore();
    void DrawRender(Mesh *mesh, Material *material) override;
    void DrawRenderers() override;
private:
    void InitWindow();
    void InitErrorInfo();
protected:
    ~OpenGLGraphicCore() override;
private:
    GLFWwindow *window = nullptr;
    Map<Shader*, OpenGLShader *> *shaders = nullptr;
    Map<Mesh*, OpenGLMesh *> *meshes = nullptr;
    Map<Texture*, OpenGLTexture *> *textures = nullptr;
};


#endif //CANVAS_1_0_OPENGLGRAPHICCORE_H
