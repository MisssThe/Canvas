//
// Created by MisThe on 2023/5/28.
//

#include "../Include/Core/Scene/Invoker/SceneInvoker.h"
#include "../Include/Core/GarbageCollection/GarbageCollection.h"

SceneInvoker* SceneInvoker::S_instance = nullptr;

void SceneInvoker::CustomMark() {
    CustomPtr::S_Mark(this->components);
    CustomPtr::S_Mark(this->psycho);
    CustomPtr::S_Mark(this->graphic);
}

SceneInvoker::~SceneInvoker() = default;

SceneInvoker *SceneInvoker::S_Instance() {
    if (SceneInvoker::S_instance == nullptr) {
        SceneInvoker::S_instance = new SceneInvoker();
    }
    return SceneInvoker::S_instance;
}

SceneInvoker::SceneInvoker() {
    this->components = new Components();
    this->psycho = new Psycho();
    this->graphic = new Graphic();
    GarbageCollection::S_AddRoot(this);
}

void SceneInvoker::Invoke() const {
    this->components->Invoke();
    this->psycho->Invoke();
    this->graphic->Invoke();
}