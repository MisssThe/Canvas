//
// Created by MisThe on 2023/5/28.
//

#include "../Include/General/Debug.h"
#include "../Include/Core/Invoker/Graphic/Graphic.h"
#include "../Include/Core/Setting/GraphicSetting.h"
#include "../Include/Core/Setting/SettingManager.h"
#include "../Include/Core/Invoker/Graphic/Core/OpenGLGraphicCore.h"
#include "../Include/Canvas.h"

void Graphic::Invoke() {
    //计算graphic data
    this->core->Invoke(this->data);
    Debug::Info("Scene Graphic", "Start Invoker");
    Canvas::S_Quit();
}

Graphic::Graphic() {
    GraphicSetting *setting = SettingManager::GetGraphicSetting();
    if (this->core == nullptr) {
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
}

void Graphic::SetGraphicData() {
    if (this->data == nullptr)
        this->data = new GraphicData();
}
