//
// Created by MisThe on 2023/5/28.
//

#include "../Include/General/Debug.h"
#include "../Include/Core/Invoker/Graphic/Graphic.h"
#include "../Include/Core/Setting/GraphicSetting.h"
#include "../Include/Core/Setting/SettingManager.h"
#include "../Include/Core/Invoker/Graphic/Core/OpenGL/OpenGLGraphicCore.h"
//#include "../Include/Canvas.h"
//#include "../Include/Core/Invoker/Graphic/Feature/GraphicFeatures.h"
#include "../Include/Core/Framework/Static.h"
#include "../Include/Core/Invoker/Graphic/Renderer.h"

void Graphic::Invoke() {
    this->SetGraphicData();
    //计算graphic data
    this->core->BeginFrame();
//    this->features->Invoke(this->data);
    this->data->renderers->IteratorWithout([this](Renderer* renderer) {
        this->core->DrawRender(renderer->mesh, renderer->material);
    });
    this->core->EndFrame();
    Debug::Info("Scene Graphic", "Start Invoker");
}

Graphic::Graphic() {
    GraphicSetting *setting = Static::S_SettingManager()->GetGraphicSetting();
    switch (setting->graphicType) {
        case GraphicSetting::OpenGL:
            core = new OpenGLGraphicCore();
            break;
        case GraphicSetting::DXD:
            core = nullptr;
            break;
        case GraphicSetting::Metal:
            core = nullptr;
            break;
        case GraphicSetting::Vulkan:
            core = nullptr;
            break;
    }
    std::string path = setting->featurePath;
    this->features = Static::S_AssetManager()->Create<GraphicFeatures>(path);
    this->data = new GraphicData();
}

void Graphic::SetGraphicData() {
    //指定core
    this->data->core = this->core;
    this->data->renderers->Clear();
    //获取所有renderer,剔除掉不正常的renderer（没有有效材质或mesh）
    Queue<Component *> *editorRenderers = Static::S_SceneManager()->Editor()->Root()->GetComponentsInChildren("Renderer", false);
    Queue<Component *> *activeRenderers = Static::S_SceneManager()->Active()->Root()->GetComponentsInChildren("Renderer", false);
    editorRenderers->IteratorWithout([this](Component *component) {
        Renderer *renderer = reinterpret_cast<Renderer *>(component);
        if (renderer->mesh == nullptr || renderer->material == nullptr)
            return;
        this->data->renderers->Push(renderer);
    });
    activeRenderers->IteratorWithout([this](Component *component) {
        Renderer *renderer = reinterpret_cast<Renderer *>(component);
        if (renderer->mesh == nullptr || renderer->material == nullptr)
            return;
        this->data->renderers->Push(renderer);
    });
    int sum = editorRenderers->Size() + activeRenderers->Size();
    Debug::Info("Graphic Renderer", "Renderer Count Is [" + std::to_string(this->data->renderers->Size()) + "], Invalid Renderer Count Is [" + std::to_string(sum) + "]");
    //填充摄像机信息

}

void Graphic::CustomMark() {
    CustomPtr::S_Mark(this->data);
    CustomPtr::S_Mark(this->core);
    CustomPtr::S_Mark(this->features);
}