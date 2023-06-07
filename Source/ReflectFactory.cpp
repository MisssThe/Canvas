//
// Created by MisThe on 2023/6/4.
//

#include "../Include/Core/Framework/ReflectFactory.h"
#include "../Include/Core/Scene/Entity/Transform.h"
#include "../Include/Core/Invoker/Graphic/Renderer.h"

Map<std::string,std::function<CustomPtr*()>> ReflectFactory::S_instances;

CustomPtr *ReflectFactory::S_Instance(std::string type) {
    if (!ReflectFactory::S_instances.Contain(type))
        return nullptr;
    return ReflectFactory::S_instances.Get(type)();
}

bool ReflectFactory::S_Register(std::string type, std::function<CustomPtr*()> func) {
    if (ReflectFactory::S_instances.Contain(type))
        return false;
    ReflectFactory::S_instances.Insert(type, func);
    return true;
}

//通过收集器收集文件夹下所有Custom Ptr子类
#define RegisterFactory(Type) bool Type##Register = ReflectFactory::S_Register(#Type, []() { return new Type(); })

void ReflectFactory::S_Initial() {
    RegisterFactory(Transform);
    RegisterFactory(Renderer);
}