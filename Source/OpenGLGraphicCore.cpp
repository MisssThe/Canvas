//
// Created by MisThe on 2023/6/3.
//

#include "../Include/Core/Invoker/Graphic/Core/OpenGL/OpenGLGraphicCore.h"
#include "../Include/General/Debug.h"
#include "../Include/Core/Setting/SettingManager.h"
#include "../Include/Canvas.h"
#include "../Include/Core/Framework/Static.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

OpenGLGraphicCore::OpenGLGraphicCore() {
    this->InitWindow();
    this->shaders = new Map<Shader*, OpenGLShader*>();
    this->meshes = new Map<Mesh*, OpenGLMesh*>();
    this->InitErrorInfo();
}

void OpenGLGraphicCore::CustomMark() {
    CustomPtr::S_Mark(this->shaders);
    CustomPtr::S_Mark(this->meshes);
}

//OpenGLGraphicCore::~OpenGLGraphicCore() {
//    glfwTerminate();
//}

void OpenGLGraphicCore::BeginFrame() {
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLGraphicCore::EndFrame() {
    glfwSwapBuffers(this->window);
    glfwPollEvents();
    if (glfwWindowShouldClose(this->window))
        Canvas::S_Quit();
}

void OpenGLGraphicCore::DrawRender(Mesh *mesh, Material *material) {
    //获取并绑定shader
    Shader* shaderKey = material->shader;
    if (shaderKey == nullptr)
        shaderKey = nullptr;
    if (!this->shaders->Contain(nullptr)) {
        this->shaders->Insert(shaderKey, new OpenGLShader(shaderKey));
    }
    OpenGLShader* shader = this->shaders->Get(shaderKey);
    if (shader == nullptr)
        return;
    shader->Bind();
    //获取并绑定网格
    if (!this->meshes->Contain(mesh))
        this->meshes->Insert(mesh, new OpenGLMesh(mesh));
    OpenGLMesh* realMesh = this->meshes->Get(mesh);
    realMesh->Bind();
    //获取并设置属性
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void OpenGLGraphicCore::DrawRenderers() {

}

void OpenGLGraphicCore::InitWindow() {
    //通过设置初始化graphic
    GraphicSetting* setting = Static::S_SettingManager()->GetGraphicSetting();
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //设置窗口边框和透明模式
    glfwWindowHint(GLFW_DECORATED, setting->useBoard);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, true);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    if (setting->width < 1 || setting->height < 1)
    {
        //不用手动释放，OpenGL在释放时会自动释放（应该）
        int monitorCount;
        GLFWmonitor** pMonitor =  glfwGetMonitors(&monitorCount);
        const GLFWvidmode* mode = glfwGetVideoMode(pMonitor[0]);
        setting->width = mode->width;
        setting->height = mode->height;
    }
    this->window = glfwCreateWindow(setting->width, setting->height, setting->name.c_str(), NULL, NULL);
    if (window == nullptr)
    {
        glfwTerminate();
        Debug::Error("Init OpenGL Graphic Core","Create Window Failed");
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Debug::Error("Init OpenGL Graphic Core","Init OpenGL Failed");
    }
    glfwSwapInterval(setting->isSync);
}

void OpenGLGraphicCore::InitErrorInfo() {

}
