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

void Graphic::Invoke() {
    //计算graphic data
//    this->core->Invoke(this->data);
    this->core->BeginFrame();
//    GraphicFeatures::Invoke(this->data);
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
}

void Graphic::SetGraphicData() {
    if (this->data == nullptr)
        this->data = new GraphicData();
}

void Graphic::CustomMark() {
    CustomPtr::S_Mark(this->data);
    CustomPtr::S_Mark(this->core);
    CustomPtr::S_Mark(this->features);
}