//
// Created by MisThe on 2023/5/25.
//

#include "../Include/Core/Scene/Invoker/Component/Component.h"

Map<std::string, std::function<Component*()>>* ComponentInstance::S_componentInstanceMap = nullptr;

void Component::Read(cereal::BinaryInputArchive &archive) {
    archive(this->enable, this->destroy);
    this->ComponentRead(archive);
}

void Component::Write(cereal::BinaryOutputArchive &archive) {
    archive(this->enable, this->destroy);
    this->ComponentWrite(archive);
}

bool ComponentInstance::S_Register(std::string type, std::function<Component *()> call) {
    if (ComponentInstance::S_componentInstanceMap == nullptr)
        ComponentInstance::S_componentInstanceMap = new Map<std::string, std::function<Component*()>>();
    if (ComponentInstance::S_componentInstanceMap->Get(type) != nullptr)
        return false;
    ComponentInstance::S_componentInstanceMap->Insert(type, call);
    return true;
}

Component *ComponentInstance::S_Instance(std::string type) {
    if (ComponentInstance::S_componentInstanceMap->Get(type) == nullptr)
        return nullptr;
    Component* component = ComponentInstance::S_componentInstanceMap->Get(type)();
    SceneInvoker::S_Instance()->components->Register(component);
    return component;
}
