//
// Created by MisThe on 2023/5/28.
//

#include "../Include/General/Debug.h"
#include "../Include/Core/Scene/Invoker/Component/ComponentsInvoker.h"

void ComponentsInvoker::Invoke() {
    Debug::Info("Scene Invoker", "Start Invoker");
    //initial queue
    this->initial->IteratorWithRemove([this](Component *component) -> bool {
        component->Initial();
        this->onEnable->Push(component);
        return false;
    });
    //on enable queue
    this->onEnable->IteratorWithRemove([this](Component *component) -> bool {
        component->OnEnable();
        this->invoke->Push(component);
        return false;
    });
    //invoke queue
    this->invoke->IteratorWithRemove([this](Component *component) -> bool {
        component->Invoke();
        if (component->enable)
            return true;
        this->onDisable->Push(component);
        return false;
    });
    //on disable queue
    this->onDisable->IteratorWithRemove([this](Component *component) -> bool {
        component->OnDisable();
        this->disabled->Push(component);
        return false;
    });
    //disabled queue
    this->disabled->IteratorWithRemove([this](Component *component) -> bool {
        if (component->enable)
            this->onEnable->Push(component);
        else if (component->destroy)
            this->destroy->Push(component);
        else
            return true;
        return false;
    });
    //destroy queue
    this->destroy->IteratorWithRemove([](Component *component) -> bool {
        component->Destroy();
        return false;
    });
}

void ComponentsInvoker::CustomMark() {
    CustomPtr::S_Mark(initial);
    CustomPtr::S_Mark(onEnable);
    CustomPtr::S_Mark(invoke);
    CustomPtr::S_Mark(onDisable);
    CustomPtr::S_Mark(disabled);
    CustomPtr::S_Mark(destroy);
}

ComponentsInvoker::ComponentsInvoker() {
    this->initial = new Queue<Component*>();
    this->onEnable = new Queue<Component*>();
    this->invoke = new Queue<Component*>();
    this->onDisable = new Queue<Component*>();
    this->disabled = new Queue<Component*>();
    this->destroy = new Queue<Component*>();
}

void ComponentsInvoker::Register(Component *component) {
    if (component == nullptr)
        return;
    this->initial->Push(component);
}
