//
// Created by MisThe on 2023/5/28.
//

#include "../Include/General/Debug.h"
#include "../Include/Core/Invoker/Graphic/Graphic.h"
#include "../Include/Core/Setting/GraphicSetting.h"
#include "../Include/Core/Setting/SettingManager.h"
#include "../Include/Core/Invoker/Graphic/Core/OpenGLGraphicCore.h"
#include "../Include/Canvas.h"
#include "../Include/Core/Invoker/Graphic/Feature/GraphicFeatures.h"
#include "../Include/Core/Framework/Static.h"
#include "../Include/Core/Invoker/Graphic/Renderer.h"

void Graphic::Invoke() {
    this->SetGraphicData();
    //计算graphic data
    this->core->BeginFrame();
    this->features->Invoke(this->data);
    this->core->EndFrame();
    Debug::Info("Scene Graphic", "Start Invoker");
//    Canvas::S_Quit();
}

Graphic::Graphic() {
    GraphicSetting *setting = Static::S_SettingManager()->GetGraphicSetting();
    if (CustomPtr::S_IsNull(this->core)) {
        switch (setting->graphicType) {
            case GraphicSetting::OpenGL:
                core = new OpenGLGraphicCore();
                break;
            case GraphicSetting::DXD:
                break;
            case GraphicSetting::Metal:
                break;
            case GraphicSetting::Vulkan:
                break;
        }
    }
    std::string path = setting->featurePath;
    this->features = Static::S_AssetManager()->Create<GraphicFeatures>(path);
    this->data = new GraphicData();
}

void Graphic::SetGraphicData() {
    this->data->renderers->Clear();
    //获取所有renderer,剔除掉不正常的renderer（没有有效材质或mesh）
    Queue<Component *> *renderers = Static::S_SceneManager()->Editor()->root->GetComponentsInChildren("Renderer");
    renderers->IteratorWithout([this](Component *component) {
        Renderer *renderer = reinterpret_cast<Renderer *>(component);
        if (renderer->mesh == nullptr || renderer->material == nullptr)
            return;
        this->data->renderers->Push(renderer);
    });
    Debug::Info("Graphic Renderer", "Renderer Count Is [" + std::to_string(this->data->renderers->Size()) + "], Invalid Renderer Count Is [" + std::to_string(renderers->Size()) + "]");
    //指定core
    this->data->core = this->core;
}

void Graphic::CustomMark() {
    CustomPtr::S_Mark(this->data);
    CustomPtr::S_Mark(this->core);
    CustomPtr::S_Mark(this->features);
}