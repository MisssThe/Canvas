//
// Created by MisThe on 2023/6/3.
//

#include "../Include/Core/Invoker/Graphic/Core/OpenGLGraphicCore.h"
#include "../Include/General/Debug.h"
#include "../Include/Core/Setting/SettingManager.h"
#include "../Include/Canvas.h"
#include "../Include/Core/Framework/Static.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

OpenGLGraphicCore::OpenGLGraphicCore() {
    //通过设置初始化graphic
    GraphicSetting* setting = Static::S_SettingManager()->GetGraphicSetting();
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_DECORATED, setting->useBoard);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, setting->useTransparent);
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

void OpenGLGraphicCore::CustomMark() {

}

//OpenGLGraphicCore::~OpenGLGraphicCore() {
//    glfwTerminate();
//}

void OpenGLGraphicCore::BeginFrame() {

}

void OpenGLGraphicCore::EndFrame() {
    glfwSwapBuffers(this->window);
    glfwPollEvents();
    if (glfwWindowShouldClose(this->window))
        Canvas::S_Quit();
}
