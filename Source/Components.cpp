//
// Created by MisThe on 2023/5/28.
//

#include "../Include/General/Debug.h"
#include "../Include/Core/Invoker/Component/Components.h"
#include "../Include/Core/Invoker/Component/Component.h"

void Components::Invoke() {
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

void Components::CustomMark() {
    CustomPtr::S_Mark(this->initial);
    CustomPtr::S_Mark(this->onEnable);
    CustomPtr::S_Mark(this->invoke);
    CustomPtr::S_Mark(this->onDisable);
    CustomPtr::S_Mark(this->disabled);
    CustomPtr::S_Mark(this->destroy);
}

Components::Components() {
    this->initial = new Queue<Component*>();
    this->onEnable = new Queue<Component*>();
    this->invoke = new Queue<Component*>();
    this->onDisable = new Queue<Component*>();
    this->disabled = new Queue<Component*>();
    this->destroy = new Queue<Component*>();
}

void Components::Register(Component *component) {
    if (component == nullptr)
        return;
    this->initial->Push(component);
}
